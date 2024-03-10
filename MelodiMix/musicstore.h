#ifndef MUSICSTORE_H
#define MUSICSTORE_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QSql>
#include <QStringList>
#include <QVector>
#include "structs.h"

class MusicStore
{
public:
    MusicStore(QString dbname, QString tablename);

    int add(QString filename);
    void remove(QString filename);

    void close();

    QVector<MusicRecord> loadAll();

    QVector<MusicRecord> loadAllFav();

    void addToFav(int id);
    void removeFromFav(int id);

private:
    QSqlDatabase db;
    QString table;
    // QSqlQuery query;

};

#endif // MUSICSTORE_H
