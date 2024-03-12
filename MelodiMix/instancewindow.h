#ifndef INSTANCEWINDOW_H
#define INSTANCEWINDOW_H


#include <QMainWindow>
#include <QSlider>
#include <QMediaPlayer>
#include <QObject>
#include "playbutton.h"

class InstanceWindow : public QObject
{
    Q_OBJECT
public:
    InstanceWindow(QMainWindow *window, QString filepath);

    void show();

    void onSetPlayerPostion(qint64 value);
    void updateProgressbarDuration(qint64 duration);
    void updateProgressbar(qint64 pos);
private:
    QMainWindow *Dwindow;
    QString filepath;
    QMediaPlayer *player;
    QSlider  *progressbar;
    PlayButton *playbutton;
    QString filename;



};

#endif // INSTANCEWINDOW_H
