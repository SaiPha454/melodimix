#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QObject>
#include <QSlider>
#include "player.h"

class ProgressBar : public QObject
{
    Q_OBJECT
public:
    ProgressBar(QSlider *slider, Player *player);

public slots:

    void updateProgressbar(qint64 pos);

    void updateProgressbarDuration(qint64 duration);

    void onSetPlayerPostion(qint64 value);

private:
    QSlider *progressbar;
    Player *player;
};

#endif // PROGRESSBAR_H
