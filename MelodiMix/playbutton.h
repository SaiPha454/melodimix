#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "clickablelabel.h"
#include <QWidget>

class PlayButton : public ClickableLabel
{
public:
    PlayButton(QWidget *parent = nullptr);

public slots:
    void onClick();
};

#endif // PLAYBUTTON_H
