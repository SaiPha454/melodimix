#include "melodimix.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);

    MelodiMix *w = new MelodiMix(nullptr, argc, argv);
    w->show();
    return a.exec();
}
