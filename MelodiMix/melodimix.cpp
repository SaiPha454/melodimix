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
#include "removeablemusicitem.h"
#include <QListWidgetItem>
#include "progressbar.h"
#include<QAudioOutput>
#include <QMediaPlayer>


MelodiMix::MelodiMix(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MelodiMix)
{
    ui->setupUi(this);


    set_app_logo();

    // create default folder
    ImportFolder::create("MelodiMix");

    navs={ui->home_nav, ui->search_nav, ui->fav_nav, ui->import_nav};
    nav_icons={ui->home_icon, ui->search_icon, ui->fav_icon, ui->import_icon};


    // int *currentSongIndex = new int(0);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput();
    player->setAudioOutput(audioOutput);

    //setup player frame
    ui->player_frame->setParent(ui->Pages->widget(0));
    playbutton = new PlayButton(ui->player_frame, player);
    playbutton->setGeometry(410,30,32,32);
    PrevButton *prevbutton = new PrevButton(ui->player_frame);
    prevbutton->setGeometry(350,30,32,32);
    NextButton *nextbutton = new NextButton(ui->player_frame);
    nextbutton->setGeometry(460,30,32,32);


    //load music list
    musicandlers= new MusicEventHandler(player, playbutton);
    musicandlers->setCurrentSongIndex(currentSongIndex);

    progressbar = new ProgressBar(ui->progressbar);

    load_music();



    nextbutton->setPlayer(player);
    nextbutton->setList(ui->music_list);
    nextbutton->setCurrentSongIndex(currentSongIndex);

    prevbutton->setPlayer(player);
    prevbutton->setList(ui->music_list);
    prevbutton->setCurrentSongIndex(currentSongIndex);


    //Events
    connect(ui->music_list, &QListWidget::itemClicked, this, &MelodiMix::onMusicItemClicked);
    connect(ui->music_list, &QListWidget::itemClicked, musicandlers, &MusicEventHandler::onMusicItemClicked);

    connect(player, &QMediaPlayer::positionChanged, progressbar, &ProgressBar::updateProgressbar);
    connect(player, &QMediaPlayer::durationChanged, progressbar, &ProgressBar::updateProgressbarDuration);

    connect(ui->progressbar, &QSlider::sliderMoved, musicandlers, &MusicEventHandler::onSetPlayerPostion);
    connect(nextbutton, &NextButton::clicked, this, &MelodiMix::skip );
    connect(prevbutton, &PrevButton::clicked, this, &MelodiMix::skip );

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

    load_music();


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


    ui->imported_songs_list->clear();
    ui->imported_files_label->clear();
}


void MelodiMix::on_import_btn_clicked()
{
    QStringList filenames = ImportFolder::import();
    ui->imported_files_label->setText(QString::number(filenames.length()) + " files were imported");
    for(QString &filename : filenames) {

        qDebug() << filename;
        RemoveableMusicItem *item =  new RemoveableMusicItem( filename, filename, ui->imported_songs_list);
        ui->imported_songs_list->insertItem(0,item);
        songs_filenames.insert(0, filename );
        ui->imported_songs_list->setItemWidget(item, item->Item);
    }
}


void MelodiMix::onMusicItemClicked(QListWidgetItem *item){
    if(item){
        if(*currentSongIndex != -1){
            MusicItem *prev_music_item = dynamic_cast<MusicItem*>(ui->music_list->item(*currentSongIndex));
            prev_music_item->setUnActive();
        }
        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        ui->song_title->setText(music_item->filename);
    }
}

void MelodiMix::load_music(){

    ui->music_list->clear();
    songs_filenames = ImportFolder::load();
    ui->music_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");

    for(int i=0;i<songs_filenames.length(); i++) {
        QString& filename= songs_filenames[i];
        MusicItem *item = new MusicItem(filename, filename, i );
        if(*currentSongIndex !=-1 && *currentSongIndex == i){
            item->setActive();
        }
        ui->music_list->addItem(item);
        ui->music_list->setItemWidget(item, item->Item);
    }
}

void MelodiMix::skip(){
    if(*currentSongIndex == -1){
        return;
    }
    ui->song_title->setText(songs_filenames[*currentSongIndex]);
    musicandlers->playAt(player, songs_filenames, *currentSongIndex);

}



void MelodiMix::set_app_logo(){

    QPixmap pixel(":/img/img/melodimix.png");
    int width = ui->logo->width();
    int height = ui->logo->height();
    ui->logo->setPixmap(pixel.scaled(width, height, Qt::KeepAspectRatio));
}
