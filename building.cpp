#include "building.h"
#include "taxi.h"
#include "game.h"

extern Game *game;


void Building::draw(int xposi,int yposi,QString s,double scale)
{
    setPixmap(QPixmap(s));
    setScale(scale);
    setPos(xposi,yposi);
}

Building::Building(int xposi, int yposi, int nomal, int special,int floor2)
{
   if(nomal!=0)
   {
           if(nomal==1)
           {
               name=":/images/building1.png";
               draw(xposi,yposi,name,1);
           }
           else if(nomal==2)
           {
               name=":/images/building2.png";
               draw(xposi,yposi,name,1);
           }
           else if(nomal==3)
           {
               name=":/images/building3.png";
               draw(xposi,yposi,name,1);
           }
   }
   else if(special!=0)
   {
           if(special==1)
           {
               name=":/images/rc.png";
               draw(xposi,yposi,name,1);
           }
           else if(special==2)
           {
               name=":/images/c5.png";
               draw(xposi,yposi,name,1);
           }
           else if(special==3)
           {
               name=":/images/chungam.png";
               draw(xposi,yposi,name,1);
           }
           else if(special==4)
           {
               name=":/images/robot.png";
               draw(xposi,yposi,name,1);
           }
           else if(special==5)
           {
               name=":/images/elementary.png";
               draw(xposi,yposi,name,1);
           }
           else if(special==6)
           {
               name=":/images/taxistop.png";
               draw(xposi,yposi,name,1);
           }
   }
   if(floor2!=0)
   {

           if(floor2==1)
           {
               name=":/images/floor2_1.png";
               draw(xposi,yposi,name,0.8);
           }
           else if(floor2==2)
           {
               name=":/images/floor2_2.png";
               draw(xposi,yposi,name,0.8);
           }
           else if(floor2==3)
           {
               name=":/images/floor2_3.png";
               draw(xposi,yposi,name,0.8);
           }
           else if(floor2==4)
           {
               name=":/images/floor2_4.png";
               draw(xposi,yposi,name,0.8);
           }
   }

   QTimer *timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
   timer->start(20);//50ms마다 timer시작
}


void Building::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Taxi))
        {
            if(game->summoner->getcount()!=1 && game->summoner->getcount()!=9 )
            {
            game->summoner->decrease_count();
            scene()->removeItem(this);
            delete this;
            return;
            }
        }
    }
    setPos(x()-20,y());
    if(pos().x()+100 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}


