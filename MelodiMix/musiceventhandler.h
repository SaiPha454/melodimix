// MusicListEventHandler.h
#ifndef MUSICEVENTHANDLER_H
#define MUSICEVENTHANDLER_H

#include <QObject>
#include <QListWidgetItem>
#include<QMediaPlayer>
#include "playbutton.h"
#include <QPixmap>
#include<QWidget>

class MusicEventHandler : public QObject
{
    Q_OBJECT

public:
    MusicEventHandler(QMediaPlayer *player, PlayButton* p_play_btn);

    void setCurrentSongIndex(int *index);
public slots:
    void onMusicItemClicked(QListWidgetItem *item);
private:
    QMediaPlayer *player;
    PlayButton *playbutton;
    QPixmap pausePixel= QPixmap(":/img/img/pause.png");
    QWidget *prevMusicItem = nullptr;
    int *currentSongIndex;

};

#endif // MUSICLISTEVENTHANDLER_H
