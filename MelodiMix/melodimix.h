#ifndef MELODIMIX_H
#define MELODIMIX_H

#include <QMainWindow>
#include<vector>
#include<QPushButton>
#include<QLabel>
#include<QListWidgetItem>

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

private slots:
    void on_home_nav_clicked();

    void on_search_nav_clicked();

    void on_fav_nav_clicked();

    void on_import_nav_clicked();

    void on_pushButton_clicked();

    void onMusicItemClicked(QListWidgetItem *item);



    void on_import_btn_clicked();

private:
    Ui::MelodiMix *ui;
};
#endif // MELODIMIX_H
