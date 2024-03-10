#ifndef FAVBUTTON_H
#define FAVBUTTON_H

#include "clickablelabel.h"
#include <QWidget>
#include <QString>
#include <QPixmap>

class FavButton : public ClickableLabel
{

public:
    FavButton(QWidget *parent = nullptr);

    void fav(bool isFav);
    void unfav();

public slots:
    void onClick();


private:
    QPixmap fav_outlined= QPixmap(":/img/img/fav_outlined.png");
    QPixmap fav_filled = QPixmap(":/img/img/fav_filled.png");
};

#endif // FAVBUTTON_H
