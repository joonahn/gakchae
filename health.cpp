#include "health.h"




Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
   health=3;
   setPlainText(QString("Health: ")+QString::number(health));//score1
   setDefaultTextColor(Qt::red);
   setFont(QFont("times",16));
}

void Health::decrease()
{
   health--;
   setPlainText(QString("Health: ") + QString::number(health));//score2
}

int Health::getHealth(){return health;}
