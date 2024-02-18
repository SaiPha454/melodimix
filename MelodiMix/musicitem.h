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
    MusicItem(const QString& subtitle);
    QWidget *Item;
    QString mp3_id="123456";


private:
    QLabel *m_titleLabel;
    QLabel *m_subtitleLabel;

};

#endif // MUSICITEM_H
