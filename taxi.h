#ifndef TAXI
#define TAXI

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <stdlib.h>
#include "building.h"
#include <QMediaPlayer>
#include "gamescene.h"
class Taxi: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Taxi(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void move();
    void moveend();
private:

    int up_down;
    int taxistop;
    int judge;
    QGraphicsScene *scene;
    QMediaPlayer * bulletsound;
    QMediaPlayer * jumpsound;
    QMediaPlayer * musicend;
    Gamescene *light;
    Gamescene * ending;
};







#endif // TAXI

