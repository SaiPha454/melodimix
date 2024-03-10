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
#include "favbutton.h"
#include "musicstore.h"
#include "favmusicitem.h"

MelodiMix::MelodiMix(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MelodiMix)
{
    ui->setupUi(this);
    musicStore = new MusicStore("melodimix.db", "music");
    uiPlayList = ui->music_list;
    set_app_logo();
    currentlyPlayingSong.id=0;
    currentlyPlayingSong.fav = false;

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
    playbutton->setGeometry(390,30,32,32);
    prevbutton = new PrevButton(ui->player_frame);
    prevbutton->setGeometry(330,30,32,32);
    nextbutton = new NextButton(ui->player_frame, uiPlayList);
    nextbutton->setGeometry(450,30,32,32);


    favbutton = new FavButton(ui->player_frame);
    favbutton->setGeometry(520,30,32,32);


    //load music list
    musicandlers= new MusicEventHandler(player, playbutton);
    musicandlers->setCurrentSongIndex(currentSong);

    progressbar = new ProgressBar(ui->progressbar);

    load_music();
    load_fav_music();


    nextbutton->setPlayer(player);
    // nextbutton->setList(uiPlayList);
    nextbutton->setCurrentSongIndex(&(*currentSong).index);

    prevbutton->setPlayer(player);
    // prevbutton->setList(uiPlayList);
    prevbutton->setCurrentSongIndex(&(*currentSong).index);

    //Events
    connect(ui->music_list, &QListWidget::itemClicked, this, &MelodiMix::onMusicItemClicked);
    connect(ui->music_list, &QListWidget::itemClicked, musicandlers, &MusicEventHandler::onMusicItemClicked);

    connect(ui->fav_list, &QListWidget::itemClicked, this, &MelodiMix::on_fav_music_clicked);


    connect(player, &QMediaPlayer::positionChanged, progressbar, &ProgressBar::updateProgressbar);
    connect(player, &QMediaPlayer::durationChanged, progressbar, &ProgressBar::updateProgressbarDuration);

    connect(ui->progressbar, &QSlider::sliderMoved, musicandlers, &MusicEventHandler::onSetPlayerPostion);
    connect(nextbutton, &NextButton::clicked, this, &MelodiMix::skip );
    connect(prevbutton, &PrevButton::clicked, this, &MelodiMix::skip );

    connect(favbutton, &FavButton::clicked, this, &MelodiMix::on_add_to_fav_btn_clciked);




    connect(this, &MelodiMix::playListChange, this, &MelodiMix::on_playlist_change);

}

MelodiMix::~MelodiMix()
{
    delete ui;
    if(musicStore != nullptr){
        musicStore->close();
    }
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

    load_fav_music();
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

        int id = musicStore->add(filename);
        RemoveableMusicItem *item =  new RemoveableMusicItem( filename, 0, ui->imported_songs_list);
        ui->imported_songs_list->insertItem(0,item);
        ui->imported_songs_list->setItemWidget(item, item->Item);

        MusicRecord record;
        record.id =id;
        record.title=filename;
        record.fav = false;
        library.insert(library.begin(), record);
    }
}


void MelodiMix::onMusicItemClicked(QListWidgetItem *item){

    qDebug() <<"Library song is being clicked";
    if(item){

        emit playListChange(Enums::Library);

        if((*currentSong).index != -1){
            MusicItem *prev_music_item = dynamic_cast<MusicItem*>(ui->music_list->item((*currentSong).index));
            prev_music_item->setUnActive();
        }
        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        ui->song_title->setText(music_item->filename);
        favbutton->fav(playlist[music_item->index].fav);

        currentlyPlayingSong.id =  playlist[music_item->index].id; //===================>
        currentlyPlayingSong.fav = playlist[music_item->index].fav;

    }
}

void MelodiMix::load_music(){

    ui->music_list->clear();
    // songs_filenames = ImportFolder::load();
    library = musicStore->loadAll();
    ui->music_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");

    for(int i=0;i<library.length(); i++) {
        QString& filename= library[i].title;
        MusicItem *item = new MusicItem(filename, library[i].id, i , library[i].fav);

        if((*currentSong).type == Enums::Library && (*currentSong).index == i){
            item->setActive();
        }
        ui->music_list->addItem(item);
        ui->music_list->setItemWidget(item, item->Item);
    }
}

void MelodiMix::load_fav_music() {

    qDebug() << "All fav music"<< (*currentSong).index;
    ui->fav_list->clear();
    fav_songs = musicStore->loadAllFav();
    ui->fav_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");
    int index=0;

    for(MusicRecord &record: fav_songs){
        FavMusicItem *item= new FavMusicItem(record.title, record.id, index);
        QObject::connect(item->favbutton, &FavButton::clicked, this, [this, item](){

            musicStore->removeFromFav(item->getId());

            if(item->index <= (*currentSong).index && (*currentSong).type == Enums::Favorite){

                qDebug()<<"Reduce by 1";

                (*currentSong).index = (*currentSong).index <= 0 ? 0 : (*currentSong).index -1;
                // (*currentSong).id = fav_songs[(*currentSong).index].id;
                // load_fav_music();
                // emit playListChange(Enums::Favorite);
            }
            load_fav_music();
            if((*currentSong).type == Enums::Favorite){
                emit playListChange(Enums::Favorite);

            }


            // emit playListChange(Enums::Favorite);

        });
        if((*currentSong).type == Enums::Favorite && (*currentSong).id == item->id && (*currentSong).index == item->index){
            item->setActive();
        }

        ui->fav_list->addItem(item);
        ui->fav_list->setItemWidget(item, item->Item);
        index+=1;
    }
}

void MelodiMix::skip(){

    if((*currentSong).index == -1 || playlist.count() <=0){
        return;
    }

    qDebug() <<"Current Playlist : ";
    for(MusicRecord &record: playlist){
        qDebug() << record.title;;
    }

    qDebug() <<"Index at ----------------------"<<(*currentSong).index;
    ui->song_title->setText(playlist[(*currentSong).index].title);
    musicandlers->playAt(player, playlist[(*currentSong).index].title);

    currentlyPlayingSong.id =  playlist[(*currentSong).index].id; //===================>
    currentlyPlayingSong.fav = playlist[(*currentSong).index].fav;


    favbutton->fav(playlist[(*currentSong).index].fav);
    (*currentSong).id = playlist[(*currentSong).index].id;

}

void MelodiMix::on_add_to_fav_btn_clciked() {

    if((*currentSong).index == -1 || (*currentSong).id != currentlyPlayingSong.id ){
        return;
    }

    if(!currentlyPlayingSong.fav){
        //Add to fav list
        musicStore->addToFav(currentlyPlayingSong.id);
        playlist[(*currentSong).index].fav = true;
        favbutton->fav(true);
        currentlyPlayingSong.fav = true;

    }else {

        musicStore->removeFromFav(currentlyPlayingSong.id);
        playlist[(*currentSong).index].fav = false;
        (*currentSong).index -=1;
        favbutton->fav(false);
        currentlyPlayingSong.fav = false;
    }
    load_fav_music();
    if((*currentSong).type == Enums::Favorite){

        emit playListChange(Enums::Favorite);
    }
}

void MelodiMix::set_app_logo(){

    QPixmap pixel(":/img/img/melodimix.png");
    int width = ui->logo->width();
    int height = ui->logo->height();
    ui->logo->setPixmap(pixel.scaled(width, height, Qt::KeepAspectRatio));
}

void MelodiMix::on_fav_music_clicked(QListWidgetItem *item){

    qDebug()<<"Fav List Widget is being clicked" << (*currentSong).index;

    if(item){

        emit playListChange(Enums::Favorite);

        if((*currentSong).index != -1 && (*currentSong).index < playlist.size()){

            qDebug() << "Prev Item : "<< (*currentSong).index;
            FavMusicItem *prev_music_item = dynamic_cast<FavMusicItem*>(ui->fav_list->item((*currentSong).index));
            prev_music_item->setUnActive();

        }
        FavMusicItem *fav_item = dynamic_cast<FavMusicItem*>(item);
        fav_item->setActive();
        ui->song_title->setText(fav_item->filename);
        favbutton->fav(true);
        (*currentSong).index = fav_item->index;
        (*currentSong).id = fav_item->id;
        (*currentSong).type = Enums::Favorite;
        musicandlers->playAt(player, playlist[(*currentSong).index].title);

        currentlyPlayingSong.id =  playlist[(*currentSong).index].id; //===================>
        currentlyPlayingSong.fav = playlist[(*currentSong).index].fav;
    }

    // load_fav_music();
}




void MelodiMix::on_playlist_change(Enums::PlayListType playlistType) {
    if(playlistType == Enums::Library){
        nextbutton->setList(ui->music_list);
        prevbutton->setList(ui->music_list);
        playlist = library;
        (*currentSong).type = Enums::Library;
    }else{
        nextbutton->setList(ui->fav_list);
        prevbutton->setList(ui->fav_list);
        playlist = fav_songs;
        (*currentSong).type = Enums::Favorite;
    }
}
