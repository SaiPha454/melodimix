#include "favbutton.h"
#include <QWidget>
#include "clickablelabel.h"


FavButton::FavButton(QWidget *parent) : ClickableLabel(parent) {

    this->setPixmap(fav_outlined.scaled(36, 25, Qt::KeepAspectRatio));
}


void FavButton::onClick(){

}


void FavButton::addToFav(QString filename){
    qDebug() << filename;
}
