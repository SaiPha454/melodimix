#include "removeablemusicitem.h"
#include <QLabel>
#include "deletebutton.h"
#include <QWidget>
#include<QListWidget>

RemoveableMusicItem::RemoveableMusicItem(QString p_title, QString p_id,QListWidget* list)
    : MusicItem(p_title, p_id, 0) {

    QWidget *test_btn = new QWidget();
    button = new DeleteButton(test_btn, p_id, list);
    button->setParent(test_btn);

    layout->addWidget(test_btn);
    title->setMinimumWidth(350);
    title->setMaximumWidth(350);

}
