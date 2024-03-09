#include "musicstore.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QCoreApplication>
#include <QStringList>

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


void MusicStore::add(QString filename){


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
        return;
    }

    qDebug() << "Data inserted successfully.";
    qDebug() <<"Add to store";
}


void MusicStore::remove(QString filename){
    qDebug() <<"Remove from store";
}

QStringList MusicStore::loadAll() {
    QStringList records;
    QSqlQuery query("SELECT * FROM "+ table);
    while(query.next()) {
        QString title = query.value("title").toString();
        records.append(title);
    }

    return records;
}

void MusicStore::close(){
    db.close();
}
