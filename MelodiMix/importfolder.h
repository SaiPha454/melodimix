#ifndef IMPORTFOLDER_H
#define IMPORTFOLDER_H

#include<QString>
#include <QStringList>

class ImportFolder
{
public:
    ImportFolder(const QString foldername);

    static QStringList import();

    static QStringList load();
};

#endif // IMPORTFOLDER_H
