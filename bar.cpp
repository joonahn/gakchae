#include "bar.h"
#include "game.h"

Bar::Bar(int color)
{
    if(color == 1)
    {
    width=550;
    red = new QPixmap();
    red->load(":/images/bar_red.png");
    setPixmap(red->scaled(width,30,Qt::IgnoreAspectRatio));
    setPos(220,430);
    }
    else if(color == 2)
    {
        gray = new QPixmap();
        gray->load(":/images/bar_gray.png");
        setPixmap(gray->scaled(555,30,Qt::IgnoreAspectRatio));
        setPos(208,430);
    }
}
