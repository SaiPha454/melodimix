#ifndef LIBRARYDELETEBUTTON_H
#define LIBRARYDELETEBUTTON_H

#include "clickablelabel.h"
#include <QWidget>
#include <QPixmap>

class LibraryDeleteButton : public ClickableLabel
{
public:
    LibraryDeleteButton(QWidget *parent = nullptr);


public slots:
    void onClick();

private:
    QPixmap deletePixel= QPixmap(":/img/img/delete.png");

};

#endif // LIBRARYDELETEBUTTON_H
