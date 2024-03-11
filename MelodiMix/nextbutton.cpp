#include "nextbutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QWidget>
#include "importfolder.h"
#include "musicitem.h"
#include "musiceventhandler.h"

NextButton::NextButton(QWidget *parent) : ClickableLabel(parent) {

    QPixmap pixel(":/img/img/next.png");
    this->setPixmap(pixel.scaled(21, 21, Qt::KeepAspectRatio));

}


