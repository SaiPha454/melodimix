#ifndef LIBRARYMUSICITEM_H
#define LIBRARYMUSICITEM_H

#include "musicitem.h"
#include "librarydeletebutton.h"


class LibraryMusicItem : public MusicItem
{
public:
     LibraryMusicItem(const QString& p_title, int id, int idx, bool is_fav);
    LibraryDeleteButton *button;
protected :

};

#endif // LIBRARYMUSICITEM_H
