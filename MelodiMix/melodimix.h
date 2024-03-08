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

QT_BEGIN_NAMESPACE
namespace Ui {
class MelodiMix;
}
QT_END_NAMESPACE

class MelodiMix : public QMainWindow
{
    Q_OBJECT

public:
    MelodiMix(QWidget *parent = nullptr);
    ~MelodiMix();
    std::vector<QPushButton*> navs;
    std::vector<QLabel*> nav_icons;
    QStringList songs_filenames;

    void set_app_logo();

    void load_music();

private slots:
    void on_home_nav_clicked();

    void on_search_nav_clicked();

    void on_fav_nav_clicked();

    void on_import_nav_clicked();

    void onMusicItemClicked(QListWidgetItem *item);
    void skip();
    void on_import_btn_clicked();


private:
    Ui::MelodiMix *ui;
    int *currentSongIndex = new int(-1);
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    PlayButton *playbutton;

    MusicEventHandler *musicandlers;
    ProgressBar *progressbar;

};
#endif // MELODIMIX_H
