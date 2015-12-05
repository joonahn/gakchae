#include "game.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QImage>
#include <QBrush>

Game::Game(QGraphicsScene *_scene, int before_money, int resttime) : QGraphicsView(_scene)
{
    Final_money=before_money;
    Final_time=resttime;
    scene=_scene;

    count=0;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(740,510);
//scene->setBackgroundBrush(QBrush(QImage(":/images/taxi_background.png")));



//create the bar
    gray = new gray_Bar();
    red = new color_Bar();
    scene->addItem(gray);
    scene->addItem(red);


//create the mini_image;
    for(int i=1; i<8;i++){
    mini[i] = new Mini_image(i);
    scene->addItem(mini[i]);
    }



//create the score
    money=new Money();
    money->setPos(money->x(),money->y()+450);
    scene->addItem(money);

    taxi_distance=new Taxi_distance();
    taxi_distance->setPos(taxi_distance->x(),taxi_distance->y()+400);
    scene->addItem(taxi_distance);

// summoner create
    int rand_time;
    rand_time=2000;
    summoner = new Summoner(scene);
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),summoner,SLOT(spawn()));

//flow time
    Final_timer = new QTimer();
    QObject::connect(Final_timer,SIGNAL(timeout()),summoner,SLOT(timeflow()));

// play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/main_bgm.mp3"));
    info = new Gameinfo();
    scene->addItem(info);

// taxi create
        taxi = new Taxi(scene);
        taxi->setFlag(QGraphicsItem::ItemIsFocusable);
        taxi->setFocus();
        scene->addItem(taxi);


    show();
}
void Game::countup()
{
    count++;
}
void Game::decrease_count()
{
    count=count-count%8;
}
void Game::decrease_time()
{
    Final_time--;
    if(Final_time==0)
    {
        //씬추가
    }
}
int Game::getFinalmoney()
{
    return Final_money;
}
int Game::getFinaltime()
{
    return Final_time;
}
