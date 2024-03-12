#include "player.h"

#include <QAudioOutput>
#include "importfolder.h"
#include <QListWidget>
#include "musicitem.h"

Player::Player() {

    player= new QMediaPlayer();
    QAudioOutput *output = new QAudioOutput();
    player->setAudioOutput(output);

}


void Player::updatePlayerInfo(int idx, int p_id, bool fav){
    index=idx;
    id = p_id;
    isfav = fav;
}

void Player::play(QString filename){

    QString songFilePath = ImportFolder::getHomePath() + "/" + filename;
    player->setSource(QUrl::fromLocalFile(songFilePath));
    player->play();

}

void Player::setResume(QString filename){

    QString songFilePath = ImportFolder::getHomePath() + "/" + filename;
    player->setSource(QUrl::fromLocalFile(songFilePath));
}

void Player::next(QListWidget *list) {

    if(currentSongIndex >= list->count()){
        currentSongIndex = -1;
    }

    if(currentSongIndex >=0 && currentSongIndex < list->count()){
        MusicItem *musicItem = dynamic_cast<MusicItem*>(list->item(currentSongIndex));
        musicItem->setUnActive();

    }

    if(currentSongIndex >= list->count() -1){
        currentSongIndex = 0;
    }else{

        currentSongIndex +=1;
    }

    MusicItem *musicItem = dynamic_cast<MusicItem*>(list->item(currentSongIndex));
    musicItem->setActive();
}

void Player::back(QListWidget *list) {

    MusicItem *prevmusicItem = dynamic_cast<MusicItem*>(list->item(currentSongIndex));
    prevmusicItem->setUnActive();

    if(currentSongIndex <= 0){
        currentSongIndex = list->count() -1;
    }else{

        currentSongIndex -=1;
    }

    MusicItem *musicItem = dynamic_cast<MusicItem*>(list->item(currentSongIndex));
    musicItem->setActive();
}

void Player::updateCurrentSongInfo(int pid, int pindex, Enums::PlayListType ptype){
    currentSongId = pid;
    currentSongIndex = pindex;
    currentSongType = ptype;
}
