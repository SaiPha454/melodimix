// musicitem.cpp
#include "musicitem.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>
#include<QPixmap>

MusicItem::MusicItem(const QString& p_title, int p_id, int p_idx, bool is_fav)
    : QListWidgetItem(p_title)
{

    filename = p_title;
    id = p_id;
    index = p_idx;
    isFav = is_fav;
    QPixmap mp3_icon(":/img/img/music_icon.png");

    Item = new QWidget();
    layout = new QHBoxLayout();

    QLabel *music_item_icon = new QLabel("");
    music_item_icon->setPixmap(mp3_icon.scaled(20,20,Qt::KeepAspectRatio));
    music_item_icon->setMaximumWidth(32);

    title = new QLabel(p_title);
    title->setStyleSheet("color: white;");
    title->setAlignment(Qt::AlignLeft);
    title->setMaximumWidth(420);
    title->setMinimumWidth(420);

    layout->addWidget(music_item_icon);
    layout->addWidget(title);

    Item->setLayout(layout);
    setSizeHint(Item->sizeHint());

}

void MusicItem::setActive() {
    Item->setStyleSheet("background-color:rgb(37,130,37);");
     // Item->setStyleSheet("background-color:black");
    // Item->setStyleSheet("background-color:red;");
}

void MusicItem::setUnActive() {
    Item->setStyleSheet("background-color:black");
}

int MusicItem::getId(){
    return id;
}

int MusicItem::getIndex(){
    return index;
}
// void MusicItem::unSetFav(){
//     isFav = false;
// }

// void MusicItem::isFav(){
//     return isFav;
// }

