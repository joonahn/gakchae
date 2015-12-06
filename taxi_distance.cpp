#include "taxi_distance.h"


Taxi_distance::Taxi_distance(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
   taxi_distance=0.00;
   setPlainText(QString("주행거리: ")+QString::number(taxi_distance)+QString("km"));//score1
   setDefaultTextColor(Qt::blue);
   setFont(QFont("times",16));
   timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(increase()));   
}

void Taxi_distance::increase()
{
    taxi_distance+=0.01;
    setPlainText(QString("주행거리: ") + QString::number(taxi_distance)+QString("km"));//score2
}

int Taxi_distance::gettaxi_distance(){return taxi_distance;}

void Taxi_distance::starttimer()
{
    timer->start(300);
}

void Taxi_distance::stoptimer()
{
    timer->stop();
}
