#ifndef PREVBUTTON_H
#define PREVBUTTON_H

#include "clickablelabel.h"
#include <QStringList>
#include <QMediaPlayer>
#include <QListWidget>

class PrevButton : public ClickableLabel
{
public:
    PrevButton(QWidget *parent = nullptr);

    void setCurrentSongIndex(int *index=0);
    void setSongList(QStringList list);
    void setPlayer(QMediaPlayer *player);
    void setList(QListWidget *list);

private:
    int *currentSongIndex;
    QStringList songList;
    QMediaPlayer *player;
    QListWidget *list;

public slots:
    void onClick();
};

#endif // PREVBUTTON_H
