#include "melodimix.h"
#include "musicitem.h"
#include "musiceventhandler.h"
#include "./ui_melodimix.h"
#include "clickablelabel.h"
#include <QLabel>
#include <QPixmap>
#include<QMessageBox>
#include<QVBoxLayout>
#include "playbutton.h"
#include "prevbutton.h"
#include "nextbutton.h"
#include "importfolder.h"

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
    MusicEventHandler *musicandlers= new MusicEventHandler();
    ui->music_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");
    MusicItem *item = new MusicItem("Love in the Summer-Taylor swift", "123");
    ui->music_list->addItem(item);
    ui->music_list->setItemWidget(item, item->Item);

    MusicItem *item2 = new MusicItem("Love in the Summer-Taylor swift", "456");
    ui->music_list->addItem(item2);
    ui->music_list->setItemWidget(item2, item2->Item);
    QObject::connect(ui->music_list, &QListWidget::itemClicked, musicandlers, &MusicEventHandler::onMusicItemClicked);
    //end of load music

    //setup player frame

    ui->player_frame->setParent(ui->Pages->widget(0));
    PlayButton *playbutton = new PlayButton(ui->player_frame, ":/img/img/pause.png");
    playbutton->setGeometry(430,30,41,41);
    PrevButton *prevbutton = new PrevButton(ui->player_frame, ":/img/img/prev.png");
    prevbutton->setGeometry(350,30,41,41);
    NextButton *nextbutton = new NextButton(ui->player_frame, ":/img/img/next.png");
    nextbutton->setGeometry(510,30,41,41);

    // create default folder
    ImportFolder *imp = new ImportFolder("MelodiMix");
}

MelodiMix::~MelodiMix()
{
    delete ui;
}

void MelodiMix::on_home_nav_clicked()
{
    ui->player_frame->setParent(ui->Pages->widget(0));
    ui->Pages->setCurrentIndex(0);
    ui->player_frame->show();

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

    ui->player_frame->setParent(ui->Pages->widget(1));
    ui->Pages->setCurrentIndex(1);
    ui->player_frame->hide();
    ui->player_frame->setParent(ui->Pages->widget(1));

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

    ui->player_frame->setParent(ui->Pages->widget(2));
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

    ui->player_frame->setParent(ui->Pages->widget(3));
    ui->Pages->setCurrentIndex(3);
    ui->player_frame->hide();

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





void MelodiMix::on_import_btn_clicked()
{
    QStringList filenames = ImportFolder::import();
    ui->imported_files_label->setText(QString::number(filenames.length()) + " files were imported");
}

