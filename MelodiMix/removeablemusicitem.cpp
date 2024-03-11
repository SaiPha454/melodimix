#include "removeablemusicitem.h"
#include <QLabel>
#include "deletebutton.h"
#include <QWidget>
#include<QListWidget>

RemoveableMusicItem::RemoveableMusicItem(QString p_title, int p_id,QListWidget* list)
    : MusicItem(p_title, p_id, 0, false) {

    title->setMinimumWidth(350);
    title->setMaximumWidth(350);

}
