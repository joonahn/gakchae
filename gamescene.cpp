#include "gamescene.h"
#include "QDebug"
#include <QKeyEvent>
Gamescene::Gamescene(int _scenenum)
{   
    scenenum=_scenenum;
    if(_scenenum == 0){setPixmap(QPixmap(":/images/taxi_background.png"));}
    else if(_scenenum == 1){setPixmap(QPixmap(":/images/taxiinfo.png"));}
    else if(_scenenum == 2){setPixmap(QPixmap(":/images/gameover1.png"));}
    else if(_scenenum == 3){setPixmap(QPixmap(":/images/gameover2.png"));}
    else if(_scenenum == 4){setPixmap(QPixmap(":/images/taxiending.png"));}

    setScale(1);
    setPos(0,0);   

    if(_scenenum == 10)
    {
        setPixmap(QPixmap(":/images/light.png"));
        setScale(0.5);
        setPos(90,425);
    }
}

void Gamescene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(scenenum==4){
            emit theend();
        }
        else
            exit(0);
    }
    else
        event->ignore();

}



