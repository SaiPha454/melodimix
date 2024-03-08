#include "nextbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>
#include "importfolder.h"
#include "musicitem.h"
#include "musiceventhandler.h"

NextButton::NextButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/next.png");
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
    this->setPixmap(pixel.scaled(21, 21, Qt::KeepAspectRatio));
}

void NextButton::setCurrentSongIndex(int *index){
    currentSongIndex = index;
}




void NextButton::setPlayer(QMediaPlayer *p_player){
    player= p_player;
}

void NextButton::setList(QListWidget *p_list){
    list = p_list;
}

void NextButton::onClick() {

    if(*currentSongIndex == -1 ) {
        return;
    }

    MusicEventHandler::setMusicItemUnActive(list->item(*currentSongIndex));

    if(*currentSongIndex >= list->count() -1){
        *currentSongIndex = 0;
    }else{

        *currentSongIndex +=1;
    }

    MusicEventHandler::setMusicItemActive(list->item(*currentSongIndex));

}


