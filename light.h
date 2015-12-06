#ifndef LIGHT
#define LIGHT


#include <QGraphicsPixmapItem>
#include <QObject>

class Light: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Light();
    void setlight();
};


#endif // LIGHT

