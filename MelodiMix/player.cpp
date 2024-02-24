// Player.cpp
#include "player.h"
#include <QDebug>

Player::Player(QObject *parent) : QObject(parent) {}

void Player::onPauseClick() {
    // Implement the action to be performed when the pause button is clicked
    qDebug() << "Pause button clicked!";
    // Add your logic here...
}
