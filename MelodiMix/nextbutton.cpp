#include "nextbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>
#include "importfolder.h"
#include "musicitem.h"

NextButton::NextButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/next.png");
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
    this->setPixmap(pixel.scaled(21, 21, Qt::KeepAspectRatio));
}

void NextButton::setCurrentSongIndex(int *index){
    currentSongIndex = index;
}


void NextButton::setSongList(QStringList list){
    songList= list;
}

void NextButton::setPlayer(QMediaPlayer *p_player){
    player= p_player;
}

void NextButton::setList(QListWidget *p_list){
    list = p_list;
}

void NextButton::onClick() {

    MusicItem *prevmusic_item = dynamic_cast<MusicItem*>(list->item(*currentSongIndex));
    // MusicItem *musicItem = dynamic_cast<MusicItem*>(list[*currentSongIndex]);
    prevmusic_item->Item->setStyleSheet("background-color:black");

    if(*currentSongIndex >= songList.length()-1){
        *currentSongIndex = 0;
    }else{

        *currentSongIndex +=1;
    }


    QString filename = songList[*currentSongIndex];
    qDebug() << songList[*currentSongIndex];
    QString songFilePath = ImportFolder::getHomePath() + "/" + filename;
    player->setSource(QUrl::fromLocalFile(songFilePath));
    player->play();

   MusicItem *music_item = dynamic_cast<MusicItem*>(list->item(*currentSongIndex));
   music_item->Item->setStyleSheet("background-color:rgb(37,130,37);");

}
