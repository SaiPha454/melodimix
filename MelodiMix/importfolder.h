#ifndef IMPORTFOLDER_H
#define IMPORTFOLDER_H

#include<QString>
#include <QStringList>

class ImportFolder
{
public:
    ImportFolder(const QString foldername);

    static QStringList import();
};

#endif // IMPORTFOLDER_H
