#ifndef FAVMUSICITEM_H
#define FAVMUSICITEM_H

#include "musicitem.h"
#include "favbutton.h"
#include "deletebutton.h"
#include <QSqlQuery>

class FavMusicItem : public QObject, public MusicItem
{
Q_OBJECT
public:
    FavMusicItem(QString title, int id, int idx);
    // int index;
    FavButton *favbutton;

private:

    QWidget *btn_frame;


};

#endif // FAVMUSICITEM_H
