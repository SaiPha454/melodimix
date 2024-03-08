#include "prevbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>
#include "musicitem.h"
#include "importfolder.h"
#include "musiceventhandler.h"

PrevButton::PrevButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/prev.png");
    this->setPixmap(pixel.scaled(21,21, Qt::KeepAspectRatio));
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}


void PrevButton::setCurrentSongIndex(int *index){
    currentSongIndex = index;
}


void PrevButton::setPlayer(QMediaPlayer *p_player){
    player= p_player;
}

void PrevButton::setList(QListWidget *p_list){
    list = p_list;
}



void PrevButton::onClick() {

    if(*currentSongIndex == -1 ) {
        return;
    }

    MusicEventHandler::setMusicItemUnActive(list->item(*currentSongIndex));

    if(*currentSongIndex <= 0){
        *currentSongIndex = list->count() -1;
    }else{

        *currentSongIndex -=1;
    }

    MusicEventHandler::setMusicItemActive(list->item(*currentSongIndex));

}
