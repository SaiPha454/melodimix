#include "playbutton.h"
#include "QWidget"
#include "QPixmap"
#include <QDebug>
#include "clickablelabel.h"

PlayButton::PlayButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/pause.png");
    // this->setGeometry(0,0,width, height);
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
    this->setPixmap(pixel.scaled(21, 21, Qt::KeepAspectRatio));
}

void PlayButton::onClick() {
    qDebug()<<"Hello I am play button";
}
