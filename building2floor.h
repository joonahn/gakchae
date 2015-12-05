#ifndef BUILDING2FLOOR
#define BUILDING2FLOOR

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QString>
class Building2floor: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

     void draw(int xpose, int ypose, QString s, double scale);
     Building2floor(int xposi,int yposi,int floor2,QGraphicsScene * _scene);
public slots:
     void move();
private:
    int floornum;
    QString name;
    QGraphicsScene * scene;

};



#endif // 2BUILDING

