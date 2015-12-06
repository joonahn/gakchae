#include "color_bar.h"
#include "game.h"

extern Game *game;

color_Bar::color_Bar()
{
    width=550;
    red = new QPixmap();
    red->load(":/images/bar_red.png");
    setPixmap(red->scaled(width,30,Qt::IgnoreAspectRatio));
    setPos(220,430);
}
