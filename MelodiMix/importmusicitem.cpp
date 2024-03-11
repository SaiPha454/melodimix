#include "importmusicitem.h"

ImportMusicItem::ImportMusicItem(QString p_title)
    : MusicItem(p_title, 0, 0, false) {

    title->setMinimumWidth(350);
    title->setMaximumWidth(350);

}
