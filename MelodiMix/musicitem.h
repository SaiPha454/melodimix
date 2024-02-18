// musicitem.h
#ifndef MUSICITEM_H
#define MUSICITEM_H

#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>
#include<QWidget>

class MusicItem : public QListWidgetItem
{
public:
    MusicItem(const QString& subtitle, const QString& id);
    QWidget *Item;
    QString mp3_id;


private:
    QLabel *m_titleLabel;
    QLabel *m_subtitleLabel;

};

#endif // MUSICITEM_H
