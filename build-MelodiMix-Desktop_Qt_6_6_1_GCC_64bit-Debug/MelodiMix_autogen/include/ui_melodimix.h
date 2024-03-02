/********************************************************************************
** Form generated from reading UI file 'melodimix.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MELODIMIX_H
#define UI_MELODIMIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MelodiMix
{
public:
    QWidget *centralwidget;
    QFrame *Nav_frame;
    QPushButton *home_nav;
    QLabel *logo;
    QLabel *home_icon;
    QPushButton *search_nav;
    QLabel *search_icon;
    QPushButton *fav_nav;
    QLabel *fav_icon;
    QPushButton *import_nav;
    QLabel *import_icon;
    QStackedWidget *Pages;
    QWidget *HomePage;
    QFrame *frame;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QListWidget *music_list;
    QFrame *player_frame;
    QLabel *plyaer_icon;
    QLabel *player_title;
    QWidget *SearchPage;
    QLabel *label_2;
    QWidget *FavPage;
    QLabel *label_3;
    QWidget *ImportPage;
    QLabel *import_page_header;
    QPushButton *import_btn;
    QListWidget *imported_songs_list;
    QLabel *imported_files_label;

    void setupUi(QMainWindow *MelodiMix)
    {
        if (MelodiMix->objectName().isEmpty())
            MelodiMix->setObjectName("MelodiMix");
        MelodiMix->resize(800, 600);
        MelodiMix->setMinimumSize(QSize(800, 600));
        MelodiMix->setMaximumSize(QSize(800, 600));
        MelodiMix->setStyleSheet(QString::fromUtf8("background-color: \"black\""));
        centralwidget = new QWidget(MelodiMix);
        centralwidget->setObjectName("centralwidget");
        Nav_frame = new QFrame(centralwidget);
        Nav_frame->setObjectName("Nav_frame");
        Nav_frame->setGeometry(QRect(0, 0, 221, 611));
        Nav_frame->setStyleSheet(QString::fromUtf8("#Nav_frame {\n"
"\n"
"	border-right:2px solid gray;\n"
"}"));
        Nav_frame->setFrameShape(QFrame::NoFrame);
        Nav_frame->setFrameShadow(QFrame::Raised);
        home_nav = new QPushButton(Nav_frame);
        home_nav->setObjectName("home_nav");
        home_nav->setGeometry(QRect(0, 180, 211, 41));
        QFont font;
        font.setBold(true);
        font.setStrikeOut(false);
        home_nav->setFont(font);
        home_nav->setLayoutDirection(Qt::LeftToRight);
        home_nav->setStyleSheet(QString::fromUtf8("border-bottom: 2px solid #C1C1C1;\n"
"color:\"white\";\n"
"background-color:\"black\";"));
        home_nav->setAutoDefault(false);
        home_nav->setFlat(true);
        logo = new QLabel(Nav_frame);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(30, 20, 150, 150));
        logo->setMinimumSize(QSize(150, 150));
        logo->setMaximumSize(QSize(150, 150));
        logo->setStyleSheet(QString::fromUtf8("border:none;"));
        home_icon = new QLabel(Nav_frame);
        home_icon->setObjectName("home_icon");
        home_icon->setGeometry(QRect(30, 190, 18, 18));
        home_icon->setMinimumSize(QSize(18, 18));
        home_icon->setMaximumSize(QSize(18, 18));
        home_icon->setStyleSheet(QString::fromUtf8("background-color:\"black\";"));
        home_icon->setPixmap(QPixmap(QString::fromUtf8(":/img/img/home.png")));
        search_nav = new QPushButton(Nav_frame);
        search_nav->setObjectName("search_nav");
        search_nav->setGeometry(QRect(0, 220, 211, 41));
        search_nav->setFont(font);
        search_nav->setStyleSheet(QString::fromUtf8("border-bottom: 2px solid #C1C1C1;\n"
"color:\"white\";"));
        search_nav->setFlat(true);
        search_icon = new QLabel(Nav_frame);
        search_icon->setObjectName("search_icon");
        search_icon->setGeometry(QRect(30, 230, 18, 18));
        search_icon->setMinimumSize(QSize(18, 18));
        search_icon->setMaximumSize(QSize(18, 18));
        search_icon->setStyleSheet(QString::fromUtf8("background-color:\"black\";"));
        search_icon->setPixmap(QPixmap(QString::fromUtf8(":/img/img/search.png")));
        fav_nav = new QPushButton(Nav_frame);
        fav_nav->setObjectName("fav_nav");
        fav_nav->setGeometry(QRect(0, 260, 211, 41));
        fav_nav->setFont(font);
        fav_nav->setStyleSheet(QString::fromUtf8("border-bottom: 2px solid #C1C1C1;\n"
"color:\"white\";"));
        fav_nav->setFlat(true);
        fav_icon = new QLabel(Nav_frame);
        fav_icon->setObjectName("fav_icon");
        fav_icon->setGeometry(QRect(30, 270, 18, 18));
        fav_icon->setMinimumSize(QSize(18, 18));
        fav_icon->setMaximumSize(QSize(18, 18));
        fav_icon->setCursor(QCursor(Qt::ArrowCursor));
        fav_icon->setStyleSheet(QString::fromUtf8("background-color:\"black\";"));
        fav_icon->setFrameShape(QFrame::NoFrame);
        fav_icon->setPixmap(QPixmap(QString::fromUtf8(":/img/img/fav.png")));
        import_nav = new QPushButton(Nav_frame);
        import_nav->setObjectName("import_nav");
        import_nav->setGeometry(QRect(0, 300, 211, 41));
        import_nav->setFont(font);
        import_nav->setStyleSheet(QString::fromUtf8("border-bottom: 2px solid #C1C1C1;\n"
"color:\"white\";"));
        import_nav->setFlat(true);
        import_icon = new QLabel(Nav_frame);
        import_icon->setObjectName("import_icon");
        import_icon->setGeometry(QRect(30, 310, 18, 18));
        import_icon->setMinimumSize(QSize(18, 18));
        import_icon->setMaximumSize(QSize(18, 18));
        import_icon->setStyleSheet(QString::fromUtf8("background-color:\"black\";"));
        import_icon->setPixmap(QPixmap(QString::fromUtf8(":/img/img/import.png")));
        Pages = new QStackedWidget(centralwidget);
        Pages->setObjectName("Pages");
        Pages->setGeometry(QRect(220, 0, 581, 591));
        Pages->setAutoFillBackground(false);
        HomePage = new QWidget();
        HomePage->setObjectName("HomePage");
        frame = new QFrame(HomePage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 571, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(60, 20, 361, 40));
        textEdit->setMinimumSize(QSize(0, 40));
        textEdit->setMaximumSize(QSize(16777215, 40));
        textEdit->setStyleSheet(QString::fromUtf8("background-color:\"white\";\n"
"color:\"black\";\n"
"border-radius:\"15px\";\n"
"padding:\"10px\""));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(430, 20, 81, 35));
        pushButton->setMinimumSize(QSize(0, 35));
        pushButton->setMaximumSize(QSize(16777215, 35));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:\"white\";\n"
"color:\"black\";\n"
"border-radius:\"15px\""));
        music_list = new QListWidget(HomePage);
        music_list->setObjectName("music_list");
        music_list->setGeometry(QRect(40, 90, 521, 421));
        player_frame = new QFrame(HomePage);
        player_frame->setObjectName("player_frame");
        player_frame->setGeometry(QRect(0, 499, 581, 101));
        player_frame->setStyleSheet(QString::fromUtf8("#player_frame{\n"
"\n"
"background-color:\"black\";\n"
"border:1px solid white;\n"
"\n"
"}"));
        player_frame->setFrameShape(QFrame::StyledPanel);
        player_frame->setFrameShadow(QFrame::Raised);
        plyaer_icon = new QLabel(player_frame);
        plyaer_icon->setObjectName("plyaer_icon");
        plyaer_icon->setGeometry(QRect(30, 20, 60, 60));
        plyaer_icon->setMinimumSize(QSize(60, 60));
        plyaer_icon->setMaximumSize(QSize(60, 60));
        plyaer_icon->setStyleSheet(QString::fromUtf8("color: white;\n"
"border-radius:40;"));
        plyaer_icon->setPixmap(QPixmap(QString::fromUtf8(":/img/img/player_icon.png")));
        player_title = new QLabel(player_frame);
        player_title->setObjectName("player_title");
        player_title->setGeometry(QRect(100, 30, 201, 31));
        QFont font1;
        font1.setPointSize(10);
        player_title->setFont(font1);
        player_title->setStyleSheet(QString::fromUtf8("color: white;"));
        Pages->addWidget(HomePage);
        SearchPage = new QWidget();
        SearchPage->setObjectName("SearchPage");
        label_2 = new QLabel(SearchPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 160, 67, 17));
        label_2->setStyleSheet(QString::fromUtf8("color:\"red\";"));
        Pages->addWidget(SearchPage);
        FavPage = new QWidget();
        FavPage->setObjectName("FavPage");
        label_3 = new QLabel(FavPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 140, 67, 17));
        label_3->setStyleSheet(QString::fromUtf8("color:\"red\""));
        Pages->addWidget(FavPage);
        ImportPage = new QWidget();
        ImportPage->setObjectName("ImportPage");
        import_page_header = new QLabel(ImportPage);
        import_page_header->setObjectName("import_page_header");
        import_page_header->setGeometry(QRect(210, 30, 201, 41));
        QFont font2;
        font2.setPointSize(17);
        import_page_header->setFont(font2);
        import_page_header->setStyleSheet(QString::fromUtf8("color:\"white\""));
        import_btn = new QPushButton(ImportPage);
        import_btn->setObjectName("import_btn");
        import_btn->setGeometry(QRect(140, 110, 331, 41));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        import_btn->setFont(font3);
        import_btn->setStyleSheet(QString::fromUtf8("color:\"black\";\n"
"background-color:\"white\";\n"
"border-radius:\"20px\""));
        imported_songs_list = new QListWidget(ImportPage);
        imported_songs_list->setObjectName("imported_songs_list");
        imported_songs_list->setGeometry(QRect(35, 231, 511, 331));
        imported_files_label = new QLabel(ImportPage);
        imported_files_label->setObjectName("imported_files_label");
        imported_files_label->setGeometry(QRect(40, 190, 431, 21));
        imported_files_label->setStyleSheet(QString::fromUtf8("color:\"white\""));
        Pages->addWidget(ImportPage);
        MelodiMix->setCentralWidget(centralwidget);

        retranslateUi(MelodiMix);

        search_nav->setDefault(false);


        QMetaObject::connectSlotsByName(MelodiMix);
    } // setupUi

    void retranslateUi(QMainWindow *MelodiMix)
    {
        MelodiMix->setWindowTitle(QCoreApplication::translate("MelodiMix", "MelodiMix", nullptr));
        home_nav->setText(QCoreApplication::translate("MelodiMix", "Home", nullptr));
        logo->setText(QString());
        home_icon->setText(QString());
        search_nav->setText(QCoreApplication::translate("MelodiMix", "Search", nullptr));
        search_icon->setText(QString());
        fav_nav->setText(QCoreApplication::translate("MelodiMix", "Favourites", nullptr));
        fav_icon->setText(QString());
        import_nav->setText(QCoreApplication::translate("MelodiMix", "Import", nullptr));
        import_icon->setText(QString());
#if QT_CONFIG(accessibility)
        textEdit->setAccessibleDescription(QCoreApplication::translate("MelodiMix", "Enter song name", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton->setText(QCoreApplication::translate("MelodiMix", "Search", nullptr));
        plyaer_icon->setText(QString());
        player_title->setText(QCoreApplication::translate("MelodiMix", "Love in the summer", nullptr));
        label_2->setText(QCoreApplication::translate("MelodiMix", "Search", nullptr));
        label_3->setText(QCoreApplication::translate("MelodiMix", "Fav Page", nullptr));
        import_page_header->setText(QCoreApplication::translate("MelodiMix", "Import song files", nullptr));
        import_btn->setText(QCoreApplication::translate("MelodiMix", "+ Import ", nullptr));
        imported_files_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MelodiMix: public Ui_MelodiMix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MELODIMIX_H
