#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include "structs.h"
#include "enums.h"
#include <QListWidget>

class Player
{
public:
    QMediaPlayer *player;
    int index=-1;
    int id=0;
    bool isfav=false;

    int currentSongId=-1;
    int currentSongIndex=-1;
    Enums::PlayListType currentSongType= Enums::Library;

    Player();
    void updatePlayerInfo(int idx, int id, bool fav);
    void play(QString filename);
    void next(QListWidget *list);
    void back(QListWidget *list);
    void updateCurrentSongInfo(int id, int index, Enums::PlayListType type);
    void setResume(QString filename);
};

#endif // PLAYER_H
