// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject {
    Q_OBJECT

public:
    explicit Player(QObject *parent = nullptr);

public slots:
    void onPauseClick(); // Declaration of the onPauseClick slot
};

#endif // PLAYER_H
