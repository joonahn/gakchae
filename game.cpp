#include "game.h"
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>
#include <QDebug>
Game::Game(QWidget *parent, int before_money, int resttime) : QGraphicsView(parent)
{
    Final_money=before_money;
    Final_time=resttime;

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,740,510);
    setScene(scene);

    background = new Gamescene(0);
    scene->addItem(background);

    count=0;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(740,510);
//gameover2_scene and bgm
    gameover2 = new Gamescene(3);
    gameover2_bgm = new QMediaPlayer();
    gameover2_bgm->setMedia(QUrl("qrc:/music/gameover2.mp3"));


//create the bar
    gray = new Bar(2);
    red = new Bar(1);
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
    summoner = new Summoner(scene);
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),summoner,SLOT(spawn()));

// flow time


// play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/main_bgm.mp3"));
    info = new Gamescene(1);
    scene->addItem(info);

// taxi create
    taxi = new Taxi(scene);
    taxi->setFlag(QGraphicsItem::ItemIsFocusable);
    taxi->setFocus();
    scene->addItem(taxi);
    connect(taxi,SIGNAL(endingsignal()),this,SLOT(theend()));
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

void Game::stop_all()
{
    money->stoptimer();
    taxi_distance->stoptimer();
    music->stop();
    timer->stop();
}
int Game::getFinalmoney()
{
    return Final_money-money->getmoney();
}
int Game::getFinaltime()
{
    return Final_time;
}

void Game::decrease_Finaltime(int time)
{
    Final_time-=time;
    if(Final_time<0)
    {
        stop_all();
        gameover2->setFlag(QGraphicsItem::ItemIsFocusable);
        gameover2->setFocus();
        gameover2_bgm->play();
        scene->addItem(gameover2);
        delete taxi;
    }
}

void Game::theend()
{
    emit ending();
}
