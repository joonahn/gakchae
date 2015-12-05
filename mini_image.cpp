#include "mini_image.h"
#include "game.h"

extern Game *game;

void Mini_image::draw(int _xposi,int _yposi,QString s,double scale)
{
    setPixmap(QPixmap(s));
    setScale(scale);
    setPos(250+_xposi,_yposi);
}

void Mini_image::move()
{
    taxi_xposi=250;
    int count=game->summoner->getcount()-1;
    setPos(taxi_xposi+count*(11),430);
}


Mini_image::Mini_image(int special)
{
    xposi=11;
    yposi=390;

    if(special==1)
    {
        name=":/images/rc.png";
        draw(xposi-11,yposi,name,0.4);
    }
    else if(special==2)
    {
        name=":/images/c5.png";
        draw(xposi*8,yposi,name,0.4);
    }
    else if(special==3)
    {
        name=":/images/chungam.png";
        draw(xposi*16,yposi,name,0.4);
    }
    else if(special==4)
    {
        name=":/images/robot.png";
        draw(xposi*24,yposi,name,0.4);
    }
    else if(special==5)
    {
        name=":/images/elementary.png";
        draw(xposi*32,yposi,name,0.4);
    }
    else if(special==6)
    {
        name=":/images/taxistop.png";
        draw(xposi*40,yposi,name,0.4);
    }
    else if(special==7)
    {
        name=":/images/taxi.png";
        draw(xposi-11,yposi,name,0.4);
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(20);

    }

}
