#include "progressbar.h"
#include <QSlider>


ProgressBar::ProgressBar(QSlider *slider) {

    progressbar = slider;
    progressbar->setStyleSheet("QSlider::groove:horizontal {"
                               "border: none;"
                               "height: 7px;"
                               "background: green;"
                               "margin: 2px 0;"
                               "}"
                               "QSlider::handle:horizontal {"
                               "background: white;"
                               "border: 1px solid white;"
                               "width: 13px;"
                               "margin: -2px 0;"
                               "border-radius: 2px;"
                               "}");
}

void ProgressBar::updateProgressbar(qint64 pos){

    progressbar->setValue(pos);
}

void ProgressBar::updateProgressbarDuration(qint64 duration){
    progressbar->setMaximum(duration);
}
