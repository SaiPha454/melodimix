// musicitem.cpp
#include "musicitem.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>
#include<QPixmap>

MusicItem::MusicItem(const QString& subtitle)
    : QListWidgetItem(subtitle)
{
    QPixmap mp3_icon(":/img/img/music_icon.png");
    Item = new QWidget();

    QHBoxLayout *layout = new QHBoxLayout(Item);

    m_titleLabel = new QLabel("");
    m_titleLabel->setPixmap(mp3_icon.scaled(20,20,Qt::KeepAspectRatio));
    m_titleLabel->setMaximumWidth(65);

    m_subtitleLabel = new QLabel(subtitle);
    m_subtitleLabel->setStyleSheet("color: white;");

    layout->addWidget(m_titleLabel);
    layout->addWidget(m_subtitleLabel);

    Item->setLayout(layout);
    setSizeHint(Item->sizeHint());

}

