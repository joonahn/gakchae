#include "money.h"
#include "game.h"

extern Game *game;
Money::Money(QGraphicsItem *parent): QGraphicsTextItem(parent)
{  
   money=2700;
   setPlainText(QString("Money: ")+QString::number(money));//score1
   setDefaultTextColor(Qt::white);
   setFont(QFont("times",16));

   timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(increase()));

   gameover1 = new Gamescene(2);
   gameover1_bgm = new QMediaPlayer();
   gameover1_bgm->setMedia(QUrl("qrc:/music/gameover1.mp3"));
}

void Money::increase()
{
    money+=100;
    setPlainText(QString("Money: ") + QString::number(money));//score2
    if(money > game->getFinalmoney())
    {
        game->stop_all();
        game->scene->addItem(gameover1);
        gameover1->setFlag(QGraphicsItem::ItemIsFocusable);
        gameover1->setFocus();
        gameover1_bgm->play();
    }
}


int Money::getmoney(){return money;}

void Money::starttimer()
{
    timer->start(2000);
}

void Money::stoptimer()
{
    timer->stop();
}
