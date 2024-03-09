#ifndef MUSICSTORE_H
#define MUSICSTORE_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QSql>
#include <QStringList>

class MusicStore
{
public:
    MusicStore(QString dbname, QString tablename);

    void add(QString filename);
    void remove(QString filename);

    void close();

    QStringList loadAll();


private:
    QSqlDatabase db;
    QString table;
    // QSqlQuery query;

};

#endif // MUSICSTORE_H
