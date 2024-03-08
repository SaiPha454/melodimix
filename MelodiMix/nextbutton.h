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
    void setPlayer(QMediaPlayer *player);
    void setList(QListWidget *list);

    static void playNext(QMediaPlayer *player, QStringList list, int index);


private:
    int *currentSongIndex;
    QMediaPlayer *player;
    QListWidget *list;


public slots:
    void onClick();
};

#endif //

