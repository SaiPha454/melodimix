// ClickableLabel.cpp
#include "clickablelabel.h"
#include<QMouseEvent>

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked(); // Emit the clicked signal when the left mouse button is pressed
    }
}
