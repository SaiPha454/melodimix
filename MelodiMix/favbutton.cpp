#include "favbutton.h"
#include <QWidget>
#include "clickablelabel.h"


FavButton::FavButton(QWidget *parent) : ClickableLabel(parent) {

    this->setPixmap(fav_outlined.scaled(36, 25, Qt::KeepAspectRatio));
}


void FavButton::fav(bool isFav){
    if(isFav){
        this->setPixmap(fav_filled.scaled(32,20, Qt::KeepAspectRatio));
    }else{
        this->setPixmap(fav_outlined.scaled(36,25, Qt::KeepAspectRatio));
    }

}

void FavButton::unfav(){
    this->setPixmap(fav_outlined.scaled(36,25, Qt::KeepAspectRatio));
}
