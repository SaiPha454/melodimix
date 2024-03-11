#include "librarydeletebutton.h"

LibraryDeleteButton::LibraryDeleteButton(QWidget *parent) : ClickableLabel(parent) {

    this->setPixmap(deletePixel.scaled(28, 16, Qt::KeepAspectRatio));
}

void LibraryDeleteButton::onClick(){

}
