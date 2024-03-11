#ifndef FAVMUSICITEM_H
#define FAVMUSICITEM_H

#include "musicitem.h"
#include "favbutton.h"
#include <QSqlQuery>
#include "musicstore.h"
#include "structs.h"

class FavMusicItem : public QObject, public MusicItem
{
Q_OBJECT
public:
    FavMusicItem(QString title, int id, int idx);
    // int index;
    FavButton *favbutton;

    void removeFromFav(MusicStore *store, currentPlayItem *currentSong);

private:

    QWidget *btn_frame;


};

#endif // FAVMUSICITEM_H
