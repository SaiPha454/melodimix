// MusicListEventHandler.cpp
#include "musiceventhandler.h"
#include"musicitem.h"
#include<QMessageBox>
#include<QListWidgetItem>
#include <QString>
#include <QMediaPlayer>
#include <QDir>
#include<QStandardPaths>
#include "playbutton.h"
#include "importfolder.h"

 MusicEventHandler::MusicEventHandler(QMediaPlayer *p_player, PlayButton *p_play_btn){
    player = p_player;
    playbutton = p_play_btn;
}

void MusicEventHandler::setMusicItemActive(QListWidgetItem *item) {


    MusicItem *musicItem = dynamic_cast<MusicItem*>(item);
    musicItem->setActive();
}

void MusicEventHandler::setMusicItemUnActive(QListWidgetItem *item) {


    MusicItem *musicItem = dynamic_cast<MusicItem*>(item);
    musicItem->setUnActive();
}

