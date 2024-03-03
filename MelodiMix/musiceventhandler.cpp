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

 MusicEventHandler::MusicEventHandler(QMediaPlayer *p_player, PlayButton *p_play_btn){
    player = p_player;
    playbutton = p_play_btn;
}

void MusicEventHandler::onMusicItemClicked(QListWidgetItem *item){
    if(item){

        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        QString filename = music_item->filename;

        QString desktopLocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QDir desktopDir(desktopLocation);
        QString f = desktopDir.filePath("MelodiMix") +"/" +filename;


        player->setSource(QUrl::fromLocalFile(f));
        player->play();
        playbutton->setPixmap(pausePixel.scaled(21, 21, Qt::KeepAspectRatio));

        if(prevMusicItem != nullptr){
            prevMusicItem->setStyleSheet("background-:transparent;");
        }
        prevMusicItem = music_item->Item;
        prevMusicItem->setStyleSheet("background-color:rgb(37,130,37);");
        *currentSongIndex = music_item->id;
    }
}

void MusicEventHandler::setCurrentSongIndex(int *index){
    currentSongIndex = index;
}
