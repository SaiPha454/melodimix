#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include "playbutton.h"

class NextButton : public PlayButton
{
public:
    NextButton(QWidget *parent = nullptr,const QString img="");

public slots:
    void onClick();
};

#endif //

