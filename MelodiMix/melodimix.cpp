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
#include <QTextEdit>
#include <QPainter>

#include "instancewindow.h"

MelodiMix::MelodiMix(QWidget *parent, int argc, char *argv[])
    : QMainWindow(parent)
    , ui(new Ui::MelodiMix)
{

    if(argc >=2) {
        InstanceWindow *IW = new InstanceWindow(this, argv[1]);
        IW->show();
        return;
    }

    ui->setupUi(this);
    set_app_logo();
    musicStore = new MusicStore("melodimix.db", "music", "resume");
    importfolder = new ImportFolder();
    importfolder->create("MelodiMix");
    player_icon_rotate_timer = new QTimer(this);


    navs={ui->home_nav, ui->library_nav, ui->fav_nav, ui->import_nav};
    nav_icons={ui->home_icon, ui->search_icon, ui->fav_icon, ui->import_icon};

    player = new Player();

    //setup player frame
    ui->player_frame->setParent(ui->Pages->widget(0));
    playbutton = new PlayButton(ui->player_frame, player->player);
    playbutton->setGeometry(390,30,32,32);

    prevbutton = new PrevButton(ui->player_frame);
    prevbutton->setGeometry(330,30,32,32);

    nextbutton = new NextButton(ui->player_frame);
    nextbutton->setGeometry(450,30,32,32);

    favbutton = new FavButton(ui->player_frame);
    favbutton->setGeometry(520,30,32,32);

    progressbar = new ProgressBar(ui->progressbar, player);

    //load music list
    musicandlers= new MusicEventHandler(player->player, playbutton);

    setResumeSong();
    load_music();
    load_fav_music();
    load_library();


    //Events
    connect(ui->music_list, &QListWidget::itemClicked, this, &MelodiMix::onMusicItemClicked);
    connect(ui->fav_list, &QListWidget::itemClicked, this, &MelodiMix::on_fav_music_clicked);


    connect(player->player, &QMediaPlayer::positionChanged, progressbar, &ProgressBar::updateProgressbar);
    connect(player->player, &QMediaPlayer::durationChanged, progressbar, &ProgressBar::updateProgressbarDuration);
    connect(ui->progressbar, &QSlider::sliderMoved, progressbar, &ProgressBar::onSetPlayerPostion);

    connect(nextbutton, &NextButton::clicked, this, &MelodiMix::on_playing_next );
    connect(nextbutton, &NextButton::clicked, this, &MelodiMix::on_skip );

    connect(prevbutton, &PrevButton::clicked, this, &MelodiMix::on_playing_previous );
    connect(prevbutton, &PrevButton::clicked, this, &MelodiMix::on_skip );
    connect(favbutton, &FavButton::clicked, this, &MelodiMix::on_add_to_fav_btn_clciked);

    connect(this, &MelodiMix::playListChange, this, &MelodiMix::on_playlist_change);
    connect(player->player, &QMediaPlayer::mediaStatusChanged, this, &MelodiMix::on_player_end);
    connect(ui->search_box, &QTextEdit::textChanged, this, &MelodiMix::onSearchTextChange);
    connect(player_icon_rotate_timer, &QTimer::timeout, this, &MelodiMix::rotatePlayerIcon);

    player_icon_rotate_timer->start(500);


    emit playListChange(player->currentSongType ? Enums::Favorite : Enums::Library);
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
    load_music();
    emit playListChange(Enums::Library);
}


void MelodiMix::onMusicItemClicked(QListWidgetItem *item){


    if(item){

        //Emit the singal that the song is to play from the library playlist.
        // Not from favorite playlist
        emit playListChange(Enums::Library);

        if(player->currentSongIndex != -1 && player->currentSongIndex < playlist.size()){
            MusicItem *prev_music_item = dynamic_cast<MusicItem*>(ui->music_list->item(player->currentSongIndex));
            prev_music_item->setUnActive();
        }
        MusicItem *music_item = dynamic_cast<MusicItem*>(item);
        ui->song_title->setText(music_item->filename);
        favbutton->fav(playlist[music_item->index].fav);
        playbutton->setPlay();
        music_item->setActive();

        player->play(music_item->filename);
        player->updateCurrentSongInfo(music_item->id, music_item->index, Enums::Library);
        player->updatePlayerInfo(music_item->index,playlist[music_item->index].id, playlist[music_item->index].fav);
        musicStore->updateResumeSong(music_item->filename, music_item->id, music_item->index, false);

    }
}

void MelodiMix::load_music(){

    ui->music_list->clear();
    library = musicStore->loadAll();

    for(int i=0;i<library.length(); i++) {
        QString& filename= library[i].title;
        MusicItem *item = new MusicItem(filename, library[i].id, i , library[i].fav);

        if(player->currentSongType== Enums::Library && player->currentSongIndex == i){
            item->setActive();
        }
        ui->music_list->addItem(item);
        ui->music_list->setItemWidget(item, item->Item);
    }
}

void MelodiMix::load_fav_music() {

    ui->fav_list->clear();
    fav_songs = musicStore->loadAllFav();

    int index=0;
    for(MusicRecord &record: fav_songs){
        FavMusicItem *item= new FavMusicItem(record.title, record.id, index);

        QObject::connect(item->favbutton, &FavButton::clicked, this, [this, item](){

            musicStore->removeFromFav(item->id);
            if(item->index <= player->currentSongIndex && player->currentSongType == Enums::Favorite && player->currentSongIndex > 0){

                player->currentSongIndex -=1;
            }
            load_fav_music();
            if(player->currentSongType == Enums::Favorite){

                emit playListChange(Enums::Favorite);
            }

        });

        if(player->currentSongType == Enums::Favorite && player->currentSongId == item->id && player->currentSongIndex == item->index){
            item->setActive();
        }
        ui->fav_list->addItem(item);
        ui->fav_list->setItemWidget(item, item->Item);
        index+=1;
    }
}

void MelodiMix::on_skip(){

    if(player->currentSongIndex == -1 || playlist.count() <=0){
        qDebug()<<"Stop skipping : Index : "<<player->currentSongIndex << " Playlist Count : "<<playlist.count();
        return;
    }

    ui->song_title->setText(playlist[player->currentSongIndex].title);
    favbutton->fav(playlist[player->currentSongIndex].fav);

    player->play(playlist[player->currentSongIndex].title);
    player->currentSongId = playlist[player->currentSongIndex].id;
    player->updatePlayerInfo(player->currentSongIndex, player->currentSongId, playlist[player->currentSongIndex].fav);
    musicStore->updateResumeSong(playlist[player->currentSongIndex].title, player->id, player->index, player->isfav);
}

void MelodiMix::on_playing_next() {

    QListWidget *list =player->currentSongType == Enums::Library ? ui->music_list : ui->fav_list;

    if(player->currentSongIndex == -1 || list->count() <=0 ) {
        return;
    }
    player->next(list);

}

void MelodiMix::on_playing_previous() {

    QListWidget *list =player->currentSongType == Enums::Library ? ui->music_list : ui->fav_list;

    if(player->currentSongIndex == -1 || list->count() <=0 ) {
        return;
    }
    player->back(list);
}

void MelodiMix::on_add_to_fav_btn_clciked() {

    // qDebug() <<"Index : "<<  (*currentSong).index <<"Current SOng id : " <<(*currentSong).id << " vs  Playing: "<<  currentlyPlayingSong.id;
    if(player->currentSongIndex == -1 || player->currentSongId != player->id ){
        return;
    }

    if(!player->isfav){
        //Add to fav list
        musicStore->addToFav(player->id);
        playlist[player->currentSongIndex].fav = true;
        favbutton->fav(true);
        player->isfav= true;
        if(player->currentSongIndex == player->index -1){
            player->currentSongIndex +=1;
        }

    }else {

        musicStore->removeFromFav(player->id);
        playlist[player->currentSongIndex].fav = false;
        favbutton->fav(false);
        player->isfav = false;

        if(player->currentSongType == Enums::Favorite && player->currentSongIndex == player->index && player->currentSongIndex > 0){
            player->currentSongIndex -=1;
        }
    }
    load_fav_music();
    if(player->currentSongType == Enums::Favorite){

        emit playListChange(Enums::Favorite);
    }
}

void MelodiMix::set_app_logo(){

    QPixmap pixel(":/img/img/logo.png");
    int width = ui->logo->width();
    int height = ui->logo->height();
    ui->logo->setPixmap(pixel.scaled(width, height, Qt::KeepAspectRatio));
}

void MelodiMix::on_fav_music_clicked(QListWidgetItem *item){

    if(item){

        emit playListChange(Enums::Favorite);

        if(player->currentSongIndex != -1 && player->currentSongIndex < playlist.size()){

            FavMusicItem *prev_music_item = dynamic_cast<FavMusicItem*>(ui->fav_list->item(player->currentSongIndex));
            prev_music_item->setUnActive();
        }

        FavMusicItem *fav_item = dynamic_cast<FavMusicItem*>(item);
        fav_item->setActive();
        ui->song_title->setText(fav_item->filename);
        favbutton->fav(true);
        playbutton->setPlay();

        player->updateCurrentSongInfo(fav_item->id, fav_item->index,Enums::Favorite);
        player->play( playlist[player->currentSongIndex].title);
        player->updatePlayerInfo(player->currentSongIndex, playlist[player->currentSongIndex].id, playlist[player->currentSongIndex].fav );
        musicStore->updateResumeSong(fav_item->filename,fav_item->id, fav_item->index, true);
    }
}




void MelodiMix::on_playlist_change(Enums::PlayListType playlistType) {
    if(playlistType == Enums::Library){

        playlist = library;
        player->currentSongType = Enums::Library;
    }else{

        playlist = fav_songs;
        player->currentSongType = Enums::Favorite;
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
            if(item->index <= player->currentSongIndex && player->currentSongIndex > 0){
                player->currentSongIndex -=1;
            }
            load_music();
            load_fav_music();
            load_library();
            if( player->currentSongType == Enums::Library ){
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

void MelodiMix::setResumeSong(){

    ResumeSong info = musicStore->getResumeSong();

    player->updateCurrentSongInfo(info.id, info.index, info.isfav ? Enums::Favorite : Enums::Library);
    player->updatePlayerInfo(info.index, info.id, info.isfav);
    player->setResume(info.title);
    ui->song_title->setText(info.title);
    favbutton->fav(info.isfav);

}

void MelodiMix::on_player_end(QMediaPlayer::MediaStatus status){
    if (status == QMediaPlayer::EndOfMedia){
        emit nextbutton->clicked();
    }
}


void MelodiMix::onSearchTextChange()
{

    QString search_text = ui->search_box->toPlainText().trimmed();
    qDebug()<<"Searching...."<< search_text;

    for(int i=0; i < ui->music_list->count(); i++){
        QListWidgetItem *item = ui->music_list->item(i);

        if (item) {
            // Compare the text of the item with the search text
            QString itemText = item->text();
            if (!itemText.contains(search_text, Qt::CaseInsensitive)) { // Case insensitive comparison
                // Hide items that do not match the search text
                item->setHidden(true);
            } else {
                // Show items that match the search text
                item->setHidden(false);
            }
        }
    }
}

void MelodiMix::rotatePlayerIcon(){

    if (!(ui->song_title->text().isEmpty())) {
        // Shift the displayed text to create a scrolling effect
        QString displayedText = ui->song_title->text();
        displayedText = displayedText.mid(1) + displayedText.at(0);
        ui->song_title->setText(displayedText);
    }




}

