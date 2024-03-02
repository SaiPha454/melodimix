// ClickableLabel.cpp
#include "clickablelabel.h"
#include<QMouseEvent>
#include<QString>

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {

    QObject::connect(this, &ClickableLabel::clicked, this, &ClickableLabel::onClick);
}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked(); // Emit the clicked signal when the left mouse button is pressed
    }
}


void ClickableLabel::onClick() {
    qDebug()<<"Hello I am Clickable!";
}
