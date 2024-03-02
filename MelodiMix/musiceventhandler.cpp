// MusicListEventHandler.cpp
#include "musiceventhandler.h"
#include"musicitem.h"
#include<QMessageBox>
#include<QListWidgetItem>
#include <QString>
#include <QMediaPlayer>
#include <QDir>
#include<QStandardPaths>
#include<QAudioOutput>


void MusicEventHandler::onMusicItemClicked(QListWidgetItem *item){
    if(item){

        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        QString filename = music_item->id;

        QString desktopLocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QDir desktopDir(desktopLocation);
        QString f = desktopDir.filePath("MelodiMix") +"/" +filename;

        QMediaPlayer *player = new QMediaPlayer;
        QAudioOutput *audioOutput = new QAudioOutput();
        player->setAudioOutput(audioOutput);
        // ...
        player->setSource(QUrl::fromLocalFile(f));
        audioOutput->setVolume(100);
        player->play();

        qDebug()<< f;
    }
}
