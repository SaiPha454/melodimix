// MusicListEventHandler.cpp
#include "musiceventhandler.h"
#include"musicitem.h"
#include<QMessageBox>
#include<QListWidgetItem>

void MusicEventHandler::onMusicItemClicked(QListWidgetItem *item){
    if(item){

        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        QMessageBox msg;
        msg.setText(music_item->mp3_id);
        msg.exec();
    }
}
