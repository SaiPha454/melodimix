#include "musicstore.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QCoreApplication>
#include <QStringList>
#include <QVector>
#include "structs.h"

MusicStore::MusicStore(QString dbname, QString tablename, QString resumeTablename) {

    // Check if the specified connection name already exists
    qDebug() << "Already exist : " << QCoreApplication::applicationDirPath() + "/" + dbname;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/" + dbname);
    table = tablename;
    resumeTable = resumeTablename;

    if(!db.open()){
        qDebug() <<"Can't open the database";
    }else{
        qDebug()<<"Connected to Database";
    }


    // QSqlQuery query;

    QSqlQuery storeTableQuery(db);


    if(!db.tables().contains(table)){
        QString store_table_query = "CREATE TABLE " +  table +" ("
                                                      "id INTEGER PRIMARY KEY,"
                                                      "title VARCHAR(255) NOT NULL,"
                                                      "favorite BOOLEAN)";

        storeTableQuery.exec(store_table_query);

    }else{
        qDebug()<<"Table already exist";
    }

    QSqlQuery resumeTableQuery(db);
    if(!db.tables().contains(resumeTable)){

        QString resume_table_query = "CREATE TABLE " +  resumeTable +" ("
                                                               "id INTEGER PRIMARY KEY,"
                                                               "song_id INTEGER,"
                                                               "song_index INTEGER,"
                                                               "song_title VARCHAR(255), "
                                                               "favorite BOOLEAN)";
        if(resumeTableQuery.exec(resume_table_query)){
            qDebug()<<"Created resume table";
        }else{
            qDebug()<<"fail to create resume table "<<resumeTableQuery.lastError().text();
        }

    }else{
        qDebug()<<"Resume Table already exist";
    }

    db.commit();
}


int MusicStore::add(QString filename){


    QSqlQuery insertQuery(db);

    insertQuery.prepare("SELECT COUNT(*) FROM "+ table + " WHERE title = :title");
    insertQuery.bindValue(":title", filename);
    insertQuery.exec();
    insertQuery.next();
    int count = insertQuery.value(0).toInt();
    if(count > 0){
        return -1;
    }

    insertQuery.prepare("INSERT INTO " + table + " (title, favorite) VALUES (:title, :favorite)");
    insertQuery.bindValue(":title", filename);
    insertQuery.bindValue(":favorite", false);
    if (!insertQuery.exec()) {
        qDebug() << "Failed to insert data:" << insertQuery.lastError().text();
        db.close();
        return 0;
    }


    qDebug() << "Data inserted successfully.";
    qDebug() <<"Add to store";
    return insertQuery.lastInsertId().toInt();
}


void MusicStore::remove(int id){

    QSqlQuery deleteQeury(db);
    deleteQeury.prepare("DELETE FROM "+ table + " WHERE id = :id");
    // deleteQeury.bindValue(":table", table);
    deleteQeury.bindValue(":id",id);
    if(deleteQeury.exec()){
        qDebug() <<"Delete successfully";
    }else{
        qDebug()<<"Fail to delete"<<deleteQeury.lastError().text();
    }
}

QVector<MusicRecord> MusicStore::loadAll() {
    QVector<MusicRecord> records;
    QSqlQuery query("SELECT * FROM "+ table);
    query.exec();
    while(query.next()) {

        MusicRecord record;
        record.title = query.value("title").toString();
        record.fav = query.value("favorite").toBool();
        record.id = query.value("id").toInt();
        records.append(record);
    }

    return records;
}


QVector<MusicRecord> MusicStore::loadAllFav() {

    QVector<MusicRecord> records;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM "+ table +" WHERE favorite = :fav");
    query.bindValue(":fav", true);
    query.exec();

    while(query.next()) {

        MusicRecord record;
        record.title = query.value("title").toString();
        record.fav = query.value("favorite").toBool();
        record.id = query.value("id").toInt();
        records.append(record);
    }

    return records;
}

void MusicStore::addToFav(int id){

    QString queryString = "UPDATE "+ table + " SET favorite = :fav WHERE id = :id";
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":fav", true);
    query.bindValue(":id", id);
    if(!query.exec()){
        qDebug() <<"Fail to update" << query.lastError().text();
        return;
    }

    qDebug() << "Updated successfully";
}

void MusicStore::removeFromFav(int id){

    QString queryString = "UPDATE "+ table + " SET favorite = :fav WHERE id = :id";
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":fav", false);
    query.bindValue(":id", id);
    if(!query.exec()){
        qDebug() <<"Fail to update" << query.lastError().text();
        return;
    }

    qDebug() << "Remove from fav successfully";
}

void MusicStore::updateResumeSong(QString title, int id, int index, bool isfav) {

    QSqlQuery selectQuery(db);
    QSqlQuery updateQuery(db);
    selectQuery.prepare("SELECT * FROM "+ resumeTable + " WHERE id = 1");
    selectQuery.exec();
    selectQuery.next();
    if(selectQuery.value(0).toInt() > 0){

        updateQuery.prepare("UPDATE "+ resumeTable + " SET "
                                                      "song_title = :title, song_id = :id,"
                                                      "song_index = :index, favorite = :fav WHERE id = 1");
        qDebug()<<"Update resume table";


    }else{

        updateQuery.prepare("INSERT INTO " + resumeTable + " (song_title, song_id, song_index, favorite) "
                                                           "VALUES (:title, :id, :index, :fav)");
        qDebug()<<"Added to resume  table";
    }
    qDebug()<<"resume title : "<< title;
    updateQuery.bindValue(":title", title);
    updateQuery.bindValue(":id", id);
    updateQuery.bindValue(":index", index);
    updateQuery.bindValue(":fav", isfav);
    if(!updateQuery.exec()){
        qDebug()<<"Error on resume table " <<updateQuery.lastError().text();
    }
}

ResumeSong MusicStore::getResumeSong(){

    QSqlQuery selectQuery(db);
    QSqlQuery storeQuery(db);

    selectQuery.prepare("SELECT * FROM "+ resumeTable + " WHERE id = 1");
    selectQuery.exec();
    selectQuery.next();

    if(selectQuery.value(0).toInt() > 0){
        storeQuery.prepare("SELECT * FROM "+ resumeTable + " WHERE id = "+ selectQuery.value("song_id").toString());
        storeQuery.exec();
        storeQuery.next();
    }
    ResumeSong resume;
    if(selectQuery.value(0).toInt() > 0 && storeQuery.value(0).toInt() > 0){
        resume.id = selectQuery.value("song_id").toInt();
        resume.index = selectQuery.value("song_index").toInt();
        resume.title = selectQuery.value("song_title").toString();
        resume.isfav = selectQuery.value("favorite").toBool();
    }else{

        resume.id = -1;
        resume.index = -1;
        resume.title = "";
        resume.isfav = false;
    }

    return resume;

}

void MusicStore::close(){
    db.close();
}
