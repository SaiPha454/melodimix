#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "clickablelabel.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QPixmap>

class PlayButton : public ClickableLabel
{
public:
    PlayButton(QWidget *parent = nullptr, QMediaPlayer *p_player= new QMediaPlayer());
    void setPlay();

private:
    QMediaPlayer *player;
    QPixmap playPixel = QPixmap(":/img/img/play.png");
    QPixmap pausePixel = QPixmap(":/img/img/pause.png");


public slots:
    void onClick();
};

#endif // PLAYBUTTON_H
