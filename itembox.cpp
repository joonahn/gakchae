#include "itembox.h"
#include <QDebug>

ItemBox::ItemBox(int i,int j, int _type)
{

    setPos(i+10,j);
    check=1;
    type = _type;

    if(type == 0) {
        setPixmap(QPixmap(":/images/image/circle.png"));
        setScale(0.8);
    }
    else if(type == 1) {
        setPixmap(QPixmap(":/images/image/roach.png"));
        setScale(1);
    }
    else if(type == 2) {
        setPixmap(QPixmap(":/images/image/gun.png"));
        setScale(1);
    }
    else if(type == 3) {
        setPixmap(QPixmap(":/images/image/burger.png"));
       setScale(1);
    }
    else if(type == 4) {
        setPixmap(QPixmap(":/images/image/hanger.png"));
       setScale(1);
    }
    else if(type == 5) {
        setPixmap(QPixmap(":/images/image/dust.png"));
       setScale(1);
    }
    else if(type == 6) {
        setPixmap(QPixmap(":/images/image/report.png"));
       setScale(1);
    }
    else if(type == 7) {
        setPixmap(QPixmap(":/images/image/61.png"));
       setScale(1);
    }
}

