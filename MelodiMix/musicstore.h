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
    MusicStore(QString dbname, QString tablename, QString resumeTable);

    int add(QString filename);
    void remove(int id);

    void close();

    QVector<MusicRecord> loadAll();

    QVector<MusicRecord> loadAllFav();

    void addToFav(int id);
    void removeFromFav(int id);

    void updateResumeSong(QString title, int id, int index, bool isfav);

    ResumeSong getResumeSong();

private:
    QSqlDatabase db;
    QString table;
    QString resumeTable;
    // QSqlQuery query;

};

#endif // MUSICSTORE_H
