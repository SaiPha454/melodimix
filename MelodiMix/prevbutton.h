#ifndef PREVBUTTON_H
#define PREVBUTTON_H

#include "clickablelabel.h"

class PrevButton : public ClickableLabel
{
public:
    PrevButton(QWidget *parent = nullptr);

public slots:
    void onClick();
};

#endif // PREVBUTTON_H
