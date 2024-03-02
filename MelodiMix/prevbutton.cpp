#include "prevbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>

PrevButton::PrevButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/prev.png");
    this->setPixmap(pixel.scaled(21,21, Qt::KeepAspectRatio));
    // this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}

void PrevButton::onClick() {
    qDebug() <<"Hello I am prev";
}
