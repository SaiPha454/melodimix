#include "prevbutton.h"
#include "playbutton.h"
#include <QDebug>
#include<QWidget>

PrevButton::PrevButton(QWidget *parent, const QString img) : PlayButton(parent, img) {}

void PrevButton::onClick() {
    qDebug() <<"Hello I am prev";
}
