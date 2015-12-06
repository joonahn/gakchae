#include "darkbed.h"

#include <QDebug>

DarkBed::DarkBed()
{
    setPixmap(QPixmap(":/images/image/black.png"));
    setPos(0,370);
    setScale(1.3);

}
 