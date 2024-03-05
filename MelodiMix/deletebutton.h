#ifndef DELETEBUTTON_H
#define DELETEBUTTON_H

#include "clickablelabel.h"
#include <QWidget>
#include<QListWidget>
#include <QStringList>

class DeleteButton : public ClickableLabel
{
public:
    DeleteButton(QWidget *parent = nullptr, const QString p_id=QString(), QListWidget* list=nullptr);


public slots:
    void onClick();
    QString id;
    QListWidget* list;

};

#endif // DELETEBUTTON_H
