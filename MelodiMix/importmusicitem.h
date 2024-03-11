#ifndef IMPORTMUSICITEM_H
#define IMPORTMUSICITEM_H

#include<QListWidgetItem>
#include <QListWidget>
#include <QString>
#include<QFrame>
#include<QLabel>
#include<QWidget>
#include "clickablelabel.h"
#include <QListWidget>
#include <QStringList>

#include "musicitem.h"
class ImportMusicItem : public MusicItem
{
public:
    ImportMusicItem(QString p_title=QString());

};

#endif // IMPORTMUSICITEM_H
