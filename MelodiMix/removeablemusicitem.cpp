#include "removeablemusicitem.h"
#include <QLabel>
#include "deletebutton.h"
#include <QWidget>
#include<QListWidget>

RemoveableMusicItem::RemoveableMusicItem(QString p_title, QString p_id,QListWidget* list)
    : MusicItem(p_title, p_id, 0) {

    QWidget *btn_frame = new QWidget();
    button = new DeleteButton(btn_frame, p_id, list);
    button->setParent(btn_frame);

    layout->addWidget(btn_frame);
    title->setMinimumWidth(350);
    title->setMaximumWidth(350);

}
