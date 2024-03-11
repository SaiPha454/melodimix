#include "favmusicitem.h"
#include <QWidget>
#include <QObject>
#include "favbutton.h"
#include <QCoreApplication>
#include <QPushButton>
#include "enums.h"

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

void FavMusicItem::removeFromFav(MusicStore *musicStore, currentPlayItem *currentSong) {

    // musicStore->removeFromFav(id);
    // if(index <= (*currentSong).index && (*currentSong).type == Enums::Favorite){

    //     (*currentSong).index = (*currentSong).index <= 0 ? 0 : (*currentSong).index -1;
    // }

}
