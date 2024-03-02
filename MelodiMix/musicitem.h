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
    MusicItem(const QString& p_title, const QString& id);
    QWidget *Item;
    QString id;

protected:

    QHBoxLayout *layout;
    // QLabel *music_item_icon;
    QLabel *title;

};

#endif // MUSICITEM_H
