/********************************************************************************
** Form generated from reading UI file 'melodimix.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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
    QWidget *SearchPage;
    QLabel *label_2;
    QWidget *FavPage;
    QLabel *label_3;
    QWidget *ImportPage;
    QLabel *label_4;

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
        music_list->setGeometry(QRect(40, 100, 521, 481));
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
        label_4 = new QLabel(ImportPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 180, 131, 17));
        label_4->setStyleSheet(QString::fromUtf8("color:\"red\""));
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
        label_2->setText(QCoreApplication::translate("MelodiMix", "Search", nullptr));
        label_3->setText(QCoreApplication::translate("MelodiMix", "Fav Page", nullptr));
        label_4->setText(QCoreApplication::translate("MelodiMix", "Import Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MelodiMix: public Ui_MelodiMix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MELODIMIX_H
