#include "nextbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>

NextButton::NextButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/next.png");
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
    this->setPixmap(pixel.scaled(21, 21, Qt::KeepAspectRatio));
}

void NextButton::onClick() {
    qDebug() <<"Hello I am next";
}
