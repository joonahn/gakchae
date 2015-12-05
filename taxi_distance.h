#ifndef TAXI_DISTANCE
#define TAXI_DISTANCE

#include<QGraphicsTextitem>
#include<QFont>
#include<QTimer>
class Taxi_distance: public QGraphicsTextItem{
Q_OBJECT
public:
    Taxi_distance(QGraphicsItem * parent=0);
    int gettaxi_distance();
    void starttimer();
    void stoptimer();
public slots:
    void increase();

private:
    double taxi_distance;
    QTimer *timer;
};




#endif // TAXI_DISTANCE

