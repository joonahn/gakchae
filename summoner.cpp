#include"summoner.h"
#include"taxi.h"
#include"game.h"

extern Game *game;

Summoner::Summoner(QGraphicsScene *_scene)
{
    scene = _scene;
    xposi= 800;
    yposi= 265;
    count = 0;
    numstart=0;
    nomalnum=3;
    floor2num=2*2;//1floor,2floor
    specialnum=1;
}



void Summoner::decrease_count()
{
   if(count>8)
   {   
    specialnum=(count/8)+1;
    game->decrease_count();
    count=count-count%8;
   }
}

int Summoner::getcount()
{
    return count;
}

void Summoner::spawn()
{
    game->decrease_Finaltime(2);
    int random_floor=1+rand()%2;
    count++;
    game->countup();
    if(1 != count%8)
    {
        if(random_floor==1)
        {
            int randnum;
            randnum=1+rand()%nomalnum;

            Building * building = new Building(xposi,yposi,randnum,0,0);//(x,y,nomalnum,floor2num,specialnum)
            scene->addItem(building);
        }
        else if(random_floor==2)
        {
            int randnum;
            randnum=1+rand()%(floor2num/2);

            yposi=165;
            Building2floor * building2floor = new Building2floor(xposi,yposi,2*randnum-1,scene);//(x,y,nomalnum,floor2num,specialnum)
            scene->addItem(building2floor);
            yposi=265;
        }
    }
    else if(1== count%8 )
    {
        Building * building3 = new Building(xposi,yposi,0,specialnum++,0);
        scene->addItem(building3);
    }
    if(count==41)
    {
       game->timer->stop();
       timerend = new QTimer();
       connect(timerend,SIGNAL(timeout()),game->taxi,SLOT(moveend()));
       timerend->start(30);
    }


}


