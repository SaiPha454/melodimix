#include "nextbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>
#include "importfolder.h"
#include "musicitem.h"
#include "musiceventhandler.h"

NextButton::NextButton(QWidget *parent, QListWidget *plist) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/next.png");
    this->setPixmap(pixel.scaled(21, 21, Qt::KeepAspectRatio));
    list = plist;
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

    qDebug()<<"Current Length of list : "<< list->count();
    if(*currentSongIndex == -1 || list->count() <=0 ) {
        return;
    }

    if(*currentSongIndex >= list->count()){
        *currentSongIndex = -1;
    }

    if(*currentSongIndex >=0 && *currentSongIndex < list->count()){
            MusicEventHandler::setMusicItemUnActive(list->item(*currentSongIndex));
    }


    if(*currentSongIndex >= list->count() -1){
        *currentSongIndex = 0;
    }else{

        *currentSongIndex +=1;
    }

    MusicEventHandler::setMusicItemActive(list->item(*currentSongIndex));



    // qDebug()<<"Current Length of list : "<< playlist->count();
    // if(*currentSongIndex == -1 ) {
    //     return;
    // }

    // MusicEventHandler::setMusicItemUnActive(playlist->item(*currentSongIndex));

    // if(*currentSongIndex >= playlist->count() -1){
    //     *currentSongIndex = 0;
    // }else{

    //     *currentSongIndex +=1;
    // }

    // MusicEventHandler::setMusicItemActive(playlist->item(*currentSongIndex));

}


