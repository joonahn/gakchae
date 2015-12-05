#ifndef MINI_IMAGE
#define MINI_IMAGE

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>


class Mini_image: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
     Mini_image(int special);
     void draw(int _xposi, int _yposi, QString s, double scale);
public slots:
     void move();
private:
     int xposi;
     int yposi;
     int taxi_xposi;
     QString name;



};


#endif // MINI_IMAGE

