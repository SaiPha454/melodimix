#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject
{
    Q_OBJECT
public:

    Enums();

    enum PlayListType {
        Library,
        Favorite
    };


};

#endif // ENUMS_H
