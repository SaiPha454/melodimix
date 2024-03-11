#include "melodimix.h"
#include "musicitem.h"
#include "musiceventhandler.h"
#include "./ui_melodimix.h"
#include "clickablelabel.h"
#include <QLabel>
#include <QPixmap>
#include<QVBoxLayout>
#include "playbutton.h"
#include "prevbutton.h"
#include "nextbutton.h"
#include "importfolder.h"
#include "importmusicitem.h"
#include <QListWidgetItem>
#include "progressbar.h"
#include<QAudioOutput>
#include <QMediaPlayer>
#include "favbutton.h"
#include "musicstore.h"
#include "favmusicitem.h"
#include "librarymusicitem.h"
#include <QMessageBox>

MelodiMix::MelodiMix(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MelodiMix)
{
    ui->setupUi(this);
    set_app_logo();
    musicStore = new MusicStore("melodimix.db", "music");
    importfolder = new ImportFolder();
    importfolder->create("MelodiMix");

    currentlyPlayingSong.id=0;
    currentlyPlayingSong.fav = false;
    currentlyPlayingSong.index = -1;


    navs={ui->home_nav, ui->library_nav, ui->fav_nav, ui->import_nav};
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
    prevbutton->setPlayer(player);
    prevbutton->setCurrentSongIndex(&(*currentSong).index);

    nextbutton = new NextButton(ui->player_frame);
    nextbutton->setGeometry(450,30,32,32);
    nextbutton->setPlayer(player);
    nextbutton->setCurrentSongIndex(&(*currentSong).index);

    favbutton = new FavButton(ui->player_frame);
    favbutton->setGeometry(520,30,32,32);

    progressbar = new ProgressBar(ui->progressbar);

    //load music list
    musicandlers= new MusicEventHandler(player, playbutton);
    musicandlers->setCurrentSongIndex(currentSong);


    load_music();
    load_fav_music();
    load_library();


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

    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MelodiMix::on_player_end);

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


void MelodiMix::on_library_nav_clicked()
{

    ui->player_frame->setParent(ui->Pages->widget(1));
    ui->Pages->setCurrentIndex(1);
    ui->player_frame->hide();
    ui->player_frame->setParent(ui->Pages->widget(1));

    QPushButton* library_nav= ui->library_nav;
    QLabel* search_icon = ui->search_icon;
    library_nav->setAutoFillBackground(true);

    for(QPushButton *btn: navs){
        if(btn->objectName() == library_nav->objectName()){
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

    load_library();
}



void MelodiMix::on_fav_nav_clicked()
{

    ui->player_frame->setParent(ui->Pages->widget(2));
    ui->Pages->setCurrentIndex(2);
    ui->player_frame->show();

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

    //clear imported list and label text
    ui->imported_songs_list->clear();
    ui->imported_files_label->clear();
}



void MelodiMix::on_import_btn_clicked()
{
    int inserted_count=0;
    QStringList filenames = importfolder->import();

    for(QString &filename : filenames) {

        int id = musicStore->add(filename);
        if(id <=0) {

            continue;
        }
        ImportMusicItem *item =  new ImportMusicItem( filename);
        ui->imported_songs_list->insertItem(0,item);
        ui->imported_songs_list->setItemWidget(item, item->Item);

        MusicRecord record;
        record.id =id;
        record.title=filename;
        record.fav = false;
        library.append(record);
        inserted_count +=1;
    }
    ui->imported_files_label->setText( QString::number(inserted_count) + " files were imported");
}


void MelodiMix::onMusicItemClicked(QListWidgetItem *item){


    if(item){

        //Emit the singal that the song is to play from the library playlist.
        // Not from favorite playlist
        emit playListChange(Enums::Library);

        if((*currentSong).index != -1){
            MusicItem *prev_music_item = dynamic_cast<MusicItem*>(ui->music_list->item((*currentSong).index));
            prev_music_item->setUnActive();
        }
        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        ui->song_title->setText(music_item->filename);
        favbutton->fav(playlist[music_item->index].fav);

        (*currentSong).id = music_item->id;
        (*currentSong).index = music_item->index;
        (*currentSong).type = Enums::Library;

        currentlyPlayingSong.id =  playlist[music_item->index].id; //===================>
        currentlyPlayingSong.fav = playlist[music_item->index].fav;
        currentlyPlayingSong.index = music_item->index;

    }
}

void MelodiMix::load_music(){

    ui->music_list->clear();
    library = musicStore->loadAll();
    // ui->music_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");

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

    ui->fav_list->clear();
    fav_songs = musicStore->loadAllFav();
    // ui->fav_list->setStyleSheet("QListWidget::item { border-bottom: 1px solid white; }");
    int index=0;
    for(MusicRecord &record: fav_songs){
        FavMusicItem *item= new FavMusicItem(record.title, record.id, index);

        QObject::connect(item->favbutton, &FavButton::clicked, this, [this, item](){

            item->removeFromFav(musicStore, currentSong);
            load_fav_music();
            if((*currentSong).type == Enums::Favorite){

                emit playListChange(Enums::Favorite);
            }

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

    ui->song_title->setText(playlist[(*currentSong).index].title);
    musicandlers->playAt(player, playlist[(*currentSong).index].title);
    favbutton->fav(playlist[(*currentSong).index].fav);
    (*currentSong).id = playlist[(*currentSong).index].id;


    //currentlyPlayingSong is the song id that the player is playing
    //it does not change even the playlist change
    currentlyPlayingSong.id =  playlist[(*currentSong).index].id;
    currentlyPlayingSong.fav = playlist[(*currentSong).index].fav;
    currentlyPlayingSong.index = (*currentSong).index;
}

void MelodiMix::on_add_to_fav_btn_clciked() {

    qDebug() <<"Index : "<<  (*currentSong).index <<"Current SOng id : " <<(*currentSong).id << " vs  Playing: "<<  currentlyPlayingSong.id;
    if((*currentSong).index == -1 || (*currentSong).id != currentlyPlayingSong.id ){
        return;
    }

    if(!currentlyPlayingSong.fav){
        //Add to fav list
        musicStore->addToFav(currentlyPlayingSong.id);
        playlist[(*currentSong).index].fav = true;
        favbutton->fav(true);
        currentlyPlayingSong.fav = true;
        if((*currentSong).index == currentlyPlayingSong.index -1){
            (*currentSong).index +=1;
        }

    }else {

        musicStore->removeFromFav(currentlyPlayingSong.id);
        playlist[(*currentSong).index].fav = false;
        favbutton->fav(false);
        currentlyPlayingSong.fav = false;

        if((*currentSong).type == Enums::Favorite && (*currentSong).index == currentlyPlayingSong.index){
            (*currentSong).index -=1;
        }
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

    if(item){

        emit playListChange(Enums::Favorite);

        if((*currentSong).index != -1 && (*currentSong).index < playlist.size()){

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
        //currentlyPlayingSong is the song id that the player is playing
        //it does not change even the playlist change
        currentlyPlayingSong.id =  playlist[(*currentSong).index].id;
        currentlyPlayingSong.fav = playlist[(*currentSong).index].fav;
        currentlyPlayingSong.index = (*currentSong).index;
    }
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


void MelodiMix::load_library(){

    ui->library_list->clear();

    int index=0;
    for(MusicRecord &record : library) {

        LibraryMusicItem *item =  new LibraryMusicItem( record.title, record.id, index, record.fav );
        connect(item->button, &LibraryDeleteButton::clicked, this, [this, item](){

            musicStore->remove(item->id);
            importfolder->removeFile(item->filename);
            if(item->index <= (*currentSong).index && (*currentSong).index > 0){

                (*currentSong).index = (*currentSong).index <= 0 ? 0 : (*currentSong).index -1;
            }
            load_music();
            load_fav_music();
            load_library();
            if( (*currentSong).type == Enums::Library ){
                emit playListChange(Enums::Library);
            }else{
                emit playListChange(Enums::Favorite);
            }
        });
        ui->library_list->addItem(item);
        ui->library_list->setItemWidget(item, item->Item);
        index++;
    }
}


void MelodiMix::on_player_end(QMediaPlayer::MediaStatus status){
    if (status == QMediaPlayer::EndOfMedia){
        emit nextbutton->clicked();
    }
}

