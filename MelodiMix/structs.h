#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include "enums.h"



struct MusicRecord {
    int id;
    QString title;
    bool fav;

};


struct PlayingSong {
    int id;
    bool fav;
    int index;

};

struct currentPlayItem {
    int id;
    int index;
    Enums::PlayListType type;

};

struct ResumeSong {
    int id;
    int index;
    QString title;
    bool isfav;
};

#endif // STRUCTS_H
