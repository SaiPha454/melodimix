#include "prevbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>
#include "musicitem.h"
#include "importfolder.h"

PrevButton::PrevButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/prev.png");
    this->setPixmap(pixel.scaled(21,21, Qt::KeepAspectRatio));
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}


void PrevButton::setCurrentSongIndex(int *index){
    currentSongIndex = index;
}


void PrevButton::setSongList(QStringList list){
    songList= list;
}

void PrevButton::setPlayer(QMediaPlayer *p_player){
    player= p_player;
}

void PrevButton::setList(QListWidget *p_list){
    list = p_list;
}



void PrevButton::onClick() {

    if(player->playbackState() != QMediaPlayer::PlayingState) {
        return;
    }

    MusicItem *prevmusic_item = dynamic_cast<MusicItem*>(list->item(*currentSongIndex));
    prevmusic_item->setUnActive();

    if(*currentSongIndex <= 0){
        *currentSongIndex = songList.length() -1;
    }else{

        *currentSongIndex -=1;
    }


    QString filename = songList[*currentSongIndex];
    qDebug() << songList[*currentSongIndex];
    QString songFilePath = ImportFolder::getHomePath() + "/" + filename;
    player->setSource(QUrl::fromLocalFile(songFilePath));
    player->play();

    MusicItem *music_item = dynamic_cast<MusicItem*>(list->item(*currentSongIndex));
    music_item->setActive();
}
