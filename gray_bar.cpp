#include "gray_bar.h"

gray_Bar::gray_Bar()
{
    gray = new QPixmap();
    gray->load(":/images/bar_gray.png");
    setPixmap(gray->scaled(555,30,Qt::IgnoreAspectRatio));
    setPos(208,430);
}
