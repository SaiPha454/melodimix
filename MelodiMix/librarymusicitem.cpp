#include "librarymusicitem.h"
#include<QWidget>
#include "librarydeletebutton.h"

LibraryMusicItem::LibraryMusicItem(const QString& p_title, int id, int idx, bool is_fav)
:MusicItem(p_title, id, idx, is_fav)
{

    QWidget *btn_frame = new QWidget();
    button = new LibraryDeleteButton(btn_frame);

    button->setParent(btn_frame);
    btn_frame->setStyleSheet("margin-left:5px");

    layout->addWidget(btn_frame);

    layout->addWidget(btn_frame);
    title->setMinimumWidth(400);
    title->setMaximumWidth(400);
}

