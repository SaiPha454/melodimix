// ClickableLabel.h
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include<QString>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
     ClickableLabel(QWidget *parent = nullptr);

signals:
    void clicked(); // Custom signal to emit when the label is clicked

public slots:
    virtual void onClick();

protected:
    void mousePressEvent(QMouseEvent *event) override; // Override mousePressEvent to handle mouse clicks
};

#endif // CLICKABLELABEL_H
