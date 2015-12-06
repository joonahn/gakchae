#include"light.h"


Light::Light(){
    setPixmap(QPixmap(":/images/light.png"));
    setScale(0.5);
    setPos(90,425);
}

void Light::setlight()
{
    setScale(1);
    setPos(25,285);
}

