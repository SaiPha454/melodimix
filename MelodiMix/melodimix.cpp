#include "melodimix.h"
#include "musicitem.h"
#include "musiceventhandler.h"
#include<player.h>
#include "./ui_melodimix.h"
#include <QLabel>
#include <QPixmap>
#include<QMessageBox>
#include<QVBoxLayout>


MelodiMix::MelodiMix(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MelodiMix)
{
    ui->setupUi(this);
    QPixmap pixel(":/img/img/melodimix.png");

    int width = ui->logo->width();
    int height = ui->logo->height();
    ui->logo->setPixmap(pixel.scaled(width, height, Qt::KeepAspectRatio));

    navs={ui->home_nav, ui->search_nav, ui->fav_nav, ui->import_nav};
    nav_icons={ui->home_icon, ui->search_icon, ui->fav_icon, ui->import_icon};

    //load music list
    ui->music_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");
    MusicItem *item = new MusicItem("Love in the Summer-Taylor swift", "123");
    ui->music_list->addItem(item);
    ui->music_list->setItemWidget(item, item->Item);

    MusicItem *item2 = new MusicItem("Love in the Summer-Taylor swift", "456");
    ui->music_list->addItem(item2);
    ui->music_list->setItemWidget(item2, item2->Item);
    connect(ui->music_list, &QListWidget::itemClicked, this, &MelodiMix::onMusicItemClicked);
    //end of load music

    //setup player frame

    Player *player = new Player();
    QVBoxLayout player_layout = new QVBoxLayout(ui->player_frame);
    player_layout.addWidget(player);

}

MelodiMix::~MelodiMix()
{
    delete ui;
}

void MelodiMix::on_home_nav_clicked()
{

    ui->Pages->setCurrentIndex(0);
    QPushButton* home_nav= ui->home_nav;
    QLabel* home_icon = ui->home_icon;
    home_nav->setAutoFillBackground(true);

    for(QPushButton *btn: navs){
        if(btn->objectName() == home_nav->objectName()){
            btn->setPalette(QPalette(QColor(Qt::gray)));
            home_icon->setStyleSheet("background-color:gray;");
        }else{
            btn->setPalette(QPalette(QColor(Qt::black)));
            for(QLabel *icon: nav_icons){
                if(icon->objectName() != home_icon->objectName()){
                    icon->setStyleSheet("background-color:black;");
                }
            }
        }
    }
}

void MelodiMix::on_search_nav_clicked()
{
    ui->Pages->setCurrentIndex(1);
    QPushButton* search_nav= ui->search_nav;
    QLabel* search_icon = ui->search_icon;
    search_nav->setAutoFillBackground(true);

    for(QPushButton *btn: navs){
        if(btn->objectName() == search_nav->objectName()){
            btn->setPalette(QPalette(QColor(Qt::gray)));
            search_icon->setStyleSheet("background-color:gray;");
        }else{
            btn->setPalette(QPalette(QColor(Qt::black)));
            for(QLabel *icon: nav_icons){
                if(icon->objectName() != search_icon->objectName()){
                    icon->setStyleSheet("background-color:black;");
                }
            }
        }
    }
}



void MelodiMix::on_fav_nav_clicked()
{
    ui->Pages->setCurrentIndex(2);
    QPushButton* fav_nav= ui->fav_nav;
    QLabel* fav_icon = ui->fav_icon;
    fav_nav->setAutoFillBackground(true);

    for(QPushButton *btn: navs){
        if(btn->objectName() == fav_nav->objectName()){
            btn->setPalette(QPalette(QColor(Qt::gray)));
            fav_icon->setStyleSheet("background-color:gray;");
        }else{
            btn->setPalette(QPalette(QColor(Qt::black)));
            for(QLabel *icon: nav_icons){
                if(icon->objectName() != fav_icon->objectName()){
                    icon->setStyleSheet("background-color:black;");
                }
            }
        }
    }
}

void MelodiMix::on_import_nav_clicked()
{
    ui->Pages->setCurrentIndex(3);
    QPushButton* import_nav= ui->import_nav;
    QLabel* import_icon = ui->import_icon;
    import_nav->setAutoFillBackground(true);

    for(QPushButton *btn: navs){
        if(btn->objectName() == import_nav->objectName()){
            btn->setPalette(QPalette(QColor(Qt::gray)));
            import_icon->setStyleSheet("background-color:gray;");
        }else{
            btn->setPalette(QPalette(QColor(Qt::black)));
            for(QLabel *icon: nav_icons){
                if(icon->objectName() != import_icon->objectName()){
                    icon->setStyleSheet("background-color:black;");
                }
            }
        }
    }
}


void MelodiMix::onMusicItemClicked(QListWidgetItem *item){
    if(item){

        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        QMessageBox msg;
        msg.setText(music_item->mp3_id);
        msg.exec();
    }
}


void MelodiMix::on_pushButton_clicked()
{

}

