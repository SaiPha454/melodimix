#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include "enums.h"



struct MusicRecord {
    int id;
    QString title;
    bool fav;

};

struct currentPlayItem {
    int id;
    int index;
    Enums::PlayListType type;

};

#endif // STRUCTS_H
