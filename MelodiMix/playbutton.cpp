#include "playbutton.h"
#include "QWidget"
#include "QPixmap"
#include <QDebug>
#include "clickablelabel.h"

PlayButton::PlayButton(QWidget *parent, QMediaPlayer *p_player) : ClickableLabel(parent) {

    // QPixmap pixel(":/img/img/play.png");
    this->setPixmap(playPixel.scaled(21, 21, Qt::KeepAspectRatio));
    player= p_player;
}

void PlayButton::setPlay(){
    this->setPixmap(pausePixel.scaled(21,21, Qt::KeepAspectRatio));
}

void PlayButton::onClick() {

    if (player->source().isEmpty()) {
        return;
    }

    if(player->playbackState() == QMediaPlayer::PlayingState) {
        this->setPixmap(playPixel.scaled(21, 21, Qt::KeepAspectRatio));
        player->pause();
    }else{
        this->setPixmap(pausePixel.scaled(21, 21, Qt::KeepAspectRatio));
        player->play();
    }
}
