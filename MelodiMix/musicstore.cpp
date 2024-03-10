#include "musicstore.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QCoreApplication>
#include <QStringList>
#include <QVector>
#include "structs.h"

MusicStore::MusicStore(QString dbname, QString tablename) {

    // Check if the specified connection name already exists
    qDebug() << "Already exist : " << QCoreApplication::applicationDirPath() + "/" + dbname;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/" + dbname);
    table = tablename;


    if(!db.open()){
        qDebug() <<"Can't open the database";
    }else{
        qDebug()<<"Connected to Database";
    }


    // QSqlQuery query;

    QSqlQuery query(db);

    if(!db.tables().contains(table)){
        QString table_query = "CREATE TABLE " +  table +" ("
                                                      "id INTEGER PRIMARY KEY,"
                                                      "title VARCHAR(255) NOT NULL,"
                                                      "favorite BOOLEAN)";
        if(query.exec(table_query)) {
            qDebug() <<"table is created successfully";
        }else{
            qDebug() <<"Fail to create table"<< query.lastError().text();
        }
    }else{
        qDebug()<<"Table already exist";



        query.prepare("SELECT * FROM "+ table); // Provide your table name here

        // Check if the query execution was successful
        if (!query.exec()) {
            qDebug() << "Failed to execute query:" << query.lastError().text();
            return ;
        }

        // Iterate over the result set and print each row's data
        while (query.next()) {
            int id = query.value(0).toInt(); // Assuming the first column is an integer (change index as needed)
            QString title = query.value(1).toString(); // Assuming the second column is a string (change index as needed)
            bool favorite = query.value(2).toBool(); // Assuming the third column is a boolean (change index as needed)

            qDebug() << "ID:" << id << "Title:" << title << "Favorite:" << favorite;
        }
    }

    db.commit();
}


int MusicStore::add(QString filename){


    QStringList tables = db.tables();

    if (tables.isEmpty()) {
        qDebug() << "No tables found in the database.";
    } else {
        qDebug() << "Tables in the database:";
        for (const QString& tableName : tables) {
            qDebug() << tableName;
        }
    }


    QSqlQuery insertQuery(db);
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


void MusicStore::remove(QString filename){
    qDebug() <<"Remove from store";
}

QVector<MusicRecord> MusicStore::loadAll() {
    QVector<MusicRecord> records;
    QSqlQuery query("SELECT * FROM "+ table);
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

void MusicStore::close(){
    db.close();
}
