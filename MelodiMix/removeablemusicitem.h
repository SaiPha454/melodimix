#ifndef REMOVEABLEMUSICITEM_H
#define REMOVEABLEMUSICITEM_H

#include<QListWidgetItem>
#include <QListWidget>
#include <QString>
#include<QFrame>
#include<QLabel>
#include<QWidget>
#include "clickablelabel.h"
#include <QListWidget>
#include <QStringList>
#include "deletebutton.h"

#include "musicitem.h"
class RemoveableMusicItem : public MusicItem
{
public:
    RemoveableMusicItem(QString p_title=QString(),  QString p_id=QString(), QListWidget* list=nullptr);


protected :
    DeleteButton *button;


};

#endif // REMOVEABLEMUSICITEM_H
