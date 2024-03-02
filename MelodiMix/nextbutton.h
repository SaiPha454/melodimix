#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include "clickablelabel.h"

class NextButton : public ClickableLabel
{
public:
    NextButton(QWidget *parent = nullptr);

public slots:
    void onClick();
};

#endif //

