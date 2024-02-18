// MusicListEventHandler.h
#ifndef MUSICEVENTHANDLER_H
#define MUSICEVENTHANDLER_H

#include <QObject>
#include <QListWidgetItem>

class MusicEventHandler : public QObject
{
    Q_OBJECT

public slots:
    void onMusicItemClicked(QListWidgetItem *item);
};

#endif // MUSICLISTEVENTHANDLER_H
