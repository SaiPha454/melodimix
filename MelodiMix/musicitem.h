// musicitem.h
#ifndef MUSICITEM_H
#define MUSICITEM_H

#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>
#include<QWidget>
#include <QHBoxLayout>

class MusicItem : public QListWidgetItem
{

public:
    MusicItem(const QString& p_title, int id, int idx, bool is_fav);
    QWidget *Item;
    QString filename;
    int id;
    int index;
    bool isFav;

    void setActive();
    void setUnActive();

    int getId();
    int getIndex();

protected:

    QHBoxLayout *layout;
    // QLabel *music_item_icon;
    QLabel *title;

};

#endif // MUSICITEM_H
