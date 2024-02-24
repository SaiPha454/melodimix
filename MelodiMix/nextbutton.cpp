#include "nextbutton.h"
#include "playbutton.h"
#include <QDebug>
#include<QWidget>

NextButton::NextButton(QWidget *parent, const QString img) : PlayButton(parent, img) {}

void NextButton::onClick() {
    qDebug() <<"Hello I am next";
}
