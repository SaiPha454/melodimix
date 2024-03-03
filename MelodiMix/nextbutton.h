#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include "clickablelabel.h"
#include <QStringList>
#include <QMediaPlayer>
#include <QListWidget>

class NextButton : public ClickableLabel
{
public:
    NextButton(QWidget *parent = nullptr);

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

#endif //

