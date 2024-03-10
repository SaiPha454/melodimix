#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include "clickablelabel.h"
#include <QStringList>
#include <QMediaPlayer>
#include <QListWidget>
#include <QVector>
#include "structs.h"

class NextButton : public ClickableLabel
{
public:
    NextButton(QWidget *parent = nullptr, QListWidget *playlist = nullptr);

    void setCurrentSongIndex(int *index=0);
    void setPlayer(QMediaPlayer *player);
    void setList(QListWidget *list);

    static void playNext(QMediaPlayer *player, QStringList list, int index);


private:
    int *currentSongIndex;
    QMediaPlayer *player;
    QListWidget *list;
    QListWidget *playlist;


public slots:
    void onClick();
};

#endif //

