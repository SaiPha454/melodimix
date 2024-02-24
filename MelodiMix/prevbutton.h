#ifndef PREVBUTTON_H
#define PREVBUTTON_H

#include "playbutton.h"

class PrevButton : public PlayButton
{
public:
    PrevButton(QWidget *parent = nullptr,const QString img="");

public slots:
    void onClick();
};

#endif // PREVBUTTON_H
