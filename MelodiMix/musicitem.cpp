// musicitem.cpp
#include "musicitem.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>
#include<QPixmap>

MusicItem::MusicItem(const QString& p_title, const QString& p_id)
    : QListWidgetItem(p_title)
{

    id = p_id;
    QPixmap mp3_icon(":/img/img/music_icon.png");

    Item = new QWidget();
    layout = new QHBoxLayout();

    QLabel *music_item_icon = new QLabel("");
    music_item_icon->setPixmap(mp3_icon.scaled(20,20,Qt::KeepAspectRatio));
    music_item_icon->setMaximumWidth(65);

    title = new QLabel(p_title);
    title->setStyleSheet("color: white;");

    layout->addWidget(music_item_icon);
    layout->addWidget(title);

    Item->setLayout(layout);
    setSizeHint(Item->sizeHint());

}

