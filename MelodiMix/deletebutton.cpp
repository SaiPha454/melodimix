#include "deletebutton.h"
#include "clickablelabel.h"
#include <QDebug>
#include<QListWidget>
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QFileDialog>
#include<QListWidgetItem>

DeleteButton::DeleteButton(QWidget *parent, const QString p_id, QListWidget* lst) : ClickableLabel(parent) {

    id = p_id;
    list = lst;
    QPixmap pixel(":/img/img/delete.png");
    this->setGeometry(0,0,15, 25);
    this->setPixmap(pixel.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}



void DeleteButton::onClick(){

    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString filePath = desktopPath + QDir::separator() + "MelodiMix" + QDir::separator() + id;

    if(QFile::remove(filePath)) {

        qDebug() << "Deleted successfully";
        QListWidgetItem *item = list->findItems(id, Qt::MatchExactly).first();
        delete item;

    }

}
