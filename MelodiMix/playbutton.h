#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "clickablelabel.h"
#include <QWidget>

class PlayButton : public ClickableLabel
{
public:
    PlayButton(QWidget *parent = nullptr,const QString img="");

public slots:
    virtual void onClick();
};

#endif // PLAYBUTTON_H
