#ifndef BUILDING
#define BUILDING

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QString>
class Building: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
public:
     void draw(int xpose, int ypose, QString s, double scale);
     Building(int xposi, int yposi, int nomal, int special, int floor2);
     QString name;
public slots:
     void move();

};


#endif // BUILDING
