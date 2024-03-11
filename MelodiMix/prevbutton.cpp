#include "prevbutton.h"
#include <QDebug>
#include<QWidget>


PrevButton::PrevButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/prev.png");
    this->setPixmap(pixel.scaled(21,21, Qt::KeepAspectRatio));
}


void PrevButton::onClick() {

}
