#ifndef IMPORTFOLDER_H
#define IMPORTFOLDER_H

#include<QString>
#include <QStringList>
#include <QStandardPaths>
#include <QDir>

class ImportFolder
{
public:
    static void create(const QString foldername);

    static QStringList import();

    static QStringList load();

    static QString getHomePath();
};

#endif // IMPORTFOLDER_H
