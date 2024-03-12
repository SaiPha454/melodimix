#include "instancewindow.h"

#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QSlider>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QObject>
#include "playbutton.h"
#include <QLabel>
#include <QStringList>
#include <QCoreApplication>
#include <QMessageBox>


InstanceWindow::InstanceWindow( QMainWindow *w, QString fpath) : Dwindow(w) {
    Dwindow->resize(500,300);
    filepath = fpath;

    QString fname = fpath.split("/").last();
    filename = fname;
    qDebug()<<"File name is : "<<fname;
    if(fname.split(".").last() !="mp3"){
        QMessageBox *msgbox = new QMessageBox();
        msgbox->setMinimumWidth(200);
        msgbox->setMinimumHeight(100);
        msgbox->setText("Invalid file type!");
        msgbox->exec();
        w->close();
    }
}

void InstanceWindow::show() {


    QPixmap logo(":/img/img/logo.png");
    QLabel *label = new QLabel(Dwindow);
    label->setGeometry(120,0,300,150);
    label->setPixmap(logo.scaled(300, 150, Qt::KeepAspectRatio));

    QLabel *songTitle = new QLabel(Dwindow);
    songTitle->setText(filename);
    songTitle->setMaximumWidth(200);
    songTitle->setMinimumWidth(200);
    songTitle->setAlignment(Qt::AlignCenter);
    songTitle->setGeometry(150,200,200,20);


    player = new QMediaPlayer();
    QAudioOutput *output = new QAudioOutput();
    player->setAudioOutput(output);




    progressbar = new QSlider(Qt::Horizontal, Dwindow);
    progressbar->setMaximumWidth(300);
    progressbar->setMinimumWidth(300);
    progressbar->setGeometry(100,250,400,10);

    progressbar->setStyleSheet("QSlider::groove:horizontal {"
                               "border: none;"
                               "height: 7px;"
                               "background: green;"
                               "margin: 2px 0;"
                               "}"
                               "QSlider::handle:horizontal {"
                               "background: white;"
                               "border: 1px solid white;"
                               "width: 13px;"
                               "margin: -2px 0;"
                               "border-radius: 2px;"
                               "}");


    QObject::connect(player, &QMediaPlayer::positionChanged, this, &InstanceWindow::updateProgressbar);
    connect(player, &QMediaPlayer::durationChanged, this, &InstanceWindow::updateProgressbarDuration);
    connect(progressbar, &QSlider::sliderMoved, this, &InstanceWindow::onSetPlayerPostion);

    playbutton = new PlayButton(Dwindow, player);
    playbutton->setGeometry(420,240,32,32);


    player->setSource(filepath);
    player->play();
    playbutton->setPlay();


}


void InstanceWindow::updateProgressbar(qint64 pos){

    progressbar->setValue(pos);
}

void InstanceWindow::updateProgressbarDuration(qint64 duration){
    progressbar->setMaximum(duration);
}

void InstanceWindow::onSetPlayerPostion(qint64 value) {

    player->setPosition(value);

}
