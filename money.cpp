#include "money.h"
#include "game.h"

extern Game *game;
Money::Money(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

   money=2700;
   setPlainText(QString("Money: ")+QString::number(money));//score1
   setDefaultTextColor(Qt::blue);
   setFont(QFont("times",16));

   timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(increase()));


}

void Money::increase()
{
    money+=100;
    setPlainText(QString("Money: ") + QString::number(money));//score2
}


int Money::getmoney(){return money;}

void Money::starttimer()
{
    timer->start(2000);
}

void Money::stoptimer()
{
    timer->stop();
}
