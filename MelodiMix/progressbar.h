#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QObject>
#include <QSlider>

class ProgressBar : public QObject
{
    Q_OBJECT
public:
    ProgressBar(QSlider *slider);

public slots:

    void updateProgressbar(qint64 pos);

    void updateProgressbarDuration(qint64 duration);

private:
    QSlider *progressbar;
};

#endif // PROGRESSBAR_H
