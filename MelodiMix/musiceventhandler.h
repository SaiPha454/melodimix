// MusicListEventHandler.h
#ifndef MUSICEVENTHANDLER_H
#define MUSICEVENTHANDLER_H

#include <QObject>
#include <QListWidgetItem>
#include<QMediaPlayer>
#include "playbutton.h"
#include <QPixmap>
#include<QWidget>
#include "structs.h"

class MusicEventHandler : public QObject
{
    Q_OBJECT

public:
    MusicEventHandler(QMediaPlayer *player, PlayButton* p_play_btn);

    void setCurrentSongIndex(currentPlayItem *item);
    void playAt(QMediaPlayer *player, QString filename);
    static void setMusicItemActive(QListWidgetItem *item);
    static void setMusicItemUnActive(QListWidgetItem *item);


public slots:
    void onMusicItemClicked(QListWidgetItem *item);

    void onSetPlayerPostion(qint64 val);
private:
    QMediaPlayer *player;
    PlayButton *playbutton;
    QPixmap pausePixel= QPixmap(":/img/img/pause.png");
    QPixmap playPixel= QPixmap(":/img/img/play.png");
    QWidget *prevMusicItem = nullptr;
    // int *currentSongIndex;
    currentPlayItem *currentSong;

};

#endif // MUSICLISTEVENTHANDLER_H
