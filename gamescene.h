#ifndef GAMESCENE
#define GAMESCENE

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Gamescene: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
     Gamescene(int _scenenum);
     void keyPressEvent(QKeyEvent * event);
private:
     int scenenum;
};


#endif // GAMESCENE

