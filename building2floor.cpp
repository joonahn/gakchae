#include "building2floor.h"
#include "taxi.h"
#include "game.h"
#include "bullet.h"
extern Game *game;

void Building2floor::draw(int xposi,int yposi,QString s,double scale)
{
    setPixmap(QPixmap(s));
    setScale(scale);
    setPos(xposi,yposi);
}

Building2floor::Building2floor(int xposi,int yposi,int floor2,QGraphicsScene * _scene)
{
   floornum=floor2;
   scene=_scene;
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


void Building2floor::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Taxi))
        {
            if(game->summoner->getcount()!=1)
            {
            game->summoner->decrease_count();
            scene->removeItem(this);
            delete this;
            return;
            }
        }
        else if(typeid(*(colliding_items[i]))== typeid(Bullet))
        {
            if(game->summoner->getcount()!=1)
            {
            scene->removeItem(this);
            Building * building1floor = new Building(pos().x()+14,285,0,0,floornum+1);
            scene->addItem(building1floor);
            delete this;
            return;
            }
        }
    }
    setPos(x()-14,y());
    if(pos().x()+100 < 0)
    {
        scene->removeItem(this);
        delete this;
    }
}
