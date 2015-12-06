#include "bullet.h"
#include "building.h"

Bullet::Bullet()
{

    setPixmap(QPixmap(":/images/bullet.png"));
    setScale(1);

   QTimer *timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   timer->start(20);//50ms
}

void Bullet::move()
{
    setPos(x()+50,y());
    if(pos().x()> 600){
     scene()->removeItem(this);
     delete this;
    }
}
