#include "playbutton.h"
#include "QWidget"
#include "QPixmap"
#include <QDebug>
#include "clickablelabel.h"

PlayButton::PlayButton(QWidget *parent, const QString img) : ClickableLabel(parent) {

    QPixmap pixel(img);
    // this->setGeometry(0,0,width, height);
    this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
    QObject::connect(this, &PlayButton::clicked, this, &PlayButton::onClick);
}

void PlayButton::onClick() {
    qDebug()<<"Hello I am play button";
}
