#ifndef MELODIMIX_H
#define MELODIMIX_H

#include <QMainWindow>
#include<vector>
#include<QPushButton>
#include<QLabel>
#include<QListWidgetItem>
#include <QStringList>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "playbutton.h"
#include "musiceventhandler.h"
#include "progressbar.h"
#include "favbutton.h"
// #include <QtSql/QSqlDatabase>
#include "musicstore.h"
#include <QVector>
#include "structs.h"
#include "nextbutton.h"
#include "enums.h"
#include "importfolder.h"
#include "player.h"
#include "prevbutton.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MelodiMix;
}
QT_END_NAMESPACE

class MelodiMix : public QMainWindow
{
    Q_OBJECT

public:
    MelodiMix(QWidget *parent = nullptr, int argc=1, char *argv[]= {});
    ~MelodiMix();
    std::vector<QPushButton*> navs;
    std::vector<QLabel*> nav_icons;
    // QVector<MusicRecord> songs_filenames;
    QVector<MusicRecord> playlist;
    QVector<MusicRecord> library;
    QVector<MusicRecord> fav_songs;
    // PlayingSong currentlyPlayingSong;


    // QStringList songs_filenames;

    void set_app_logo();

    void load_music();

    void load_fav_music();

    void setResumeSong();

    Q_ENUM(Enums::PlayListType)

signals:
    void playListChange(Enums::PlayListType);

private slots:
    void on_home_nav_clicked();

    void on_library_nav_clicked();

    void on_fav_nav_clicked();

    void on_import_nav_clicked();

    void onMusicItemClicked(QListWidgetItem *item);
    void on_skip();
    void on_import_btn_clicked();

    void on_add_to_fav_btn_clciked();
    void on_fav_music_clicked(QListWidgetItem *item);

    void on_playlist_change(Enums::PlayListType);

    void load_library();

    void on_player_end(QMediaPlayer::MediaStatus status);
    void on_playing_next();
    void on_playing_previous();

    void onSearchTextChange();

    void scroll_song_title();

private:

    Ui::MelodiMix *ui;

    Player *player;
    QAudioOutput *audioOutput;
    PlayButton *playbutton;

    MusicEventHandler *musicandlers;
    ProgressBar *progressbar;
    FavButton *favbutton;

    MusicStore *musicStore = nullptr;
    PrevButton *prevbutton;
    NextButton *nextbutton;

    ImportFolder *importfolder;

    int player_icon_rotate_angle = 0;
    QTimer *scroll_title_timer;

};
#endif // MELODIMIX_H
