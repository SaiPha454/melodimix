#include "favmusicitem.h"
#include <QWidget>
#include <QObject>
#include "favbutton.h"
#include <QCoreApplication>
#include <QPushButton>
#include "deletebutton.h"

FavMusicItem::FavMusicItem(QString p_title, int p_id, int idx) : MusicItem(p_title, p_id, idx, true) {

    btn_frame = new QWidget();
    favbutton = new FavButton(btn_frame);
    favbutton->fav(true);

    favbutton->setParent(btn_frame);
    btn_frame->setStyleSheet("margin-left:20px");

    layout->addWidget(btn_frame);

    layout->addWidget(btn_frame);
    title->setMinimumWidth(400);
    title->setMaximumWidth(400);

}
