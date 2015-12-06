#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>


class Bullet: public QObject, public QGraphicsPixmapItem{
   Q_OBJECT
public:
     Bullet();
public slots:
     void move();

};

#endif // BULLET

