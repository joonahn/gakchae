#include "taxi.h"
#include "bullet.h"
#include "game.h"

extern Game *game;

Taxi::Taxi(QGraphicsScene * _scene)
{
    scene=_scene;
    judge=0;

    setPixmap(QPixmap(":/images/taxi.png"));
    setScale(1);
    setPos(50,425);
    light = new Gamescene(10);
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/music/shotgun.mp3"));
    jumpsound = new QMediaPlayer();
    jumpsound->setMedia(QUrl("qrc:/music/Jump.wav"));
    musicend = new QMediaPlayer();
    musicend->setMedia(QUrl("qrc:/music/endingsong.mp3"));

    scene->addItem(light);
    taxistop=1;
    up_down=2;
    this->setFocus();
}

void Taxi::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(judge==0)
        {
            game->taxi->setPos(50,315);
            game->taxi->setScale(1);
            light->setScale(1);
            light->setPos(25,285);
            scene->removeItem(game->info);
            game->money->starttimer();
            game->taxi_distance->starttimer();
            game->timer->start(2000);
            game->music->play();
            judge++;
        }

        jumpsound->play();
        QTimer *timer = new QTimer();

        if(up_down==2)//during jump can't move
        {
            up_down=1;
            connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(20);
            if(pos().y() == 315)
            {
                if(taxistop==0)
                {
                    timer->stop();
                    delete timer;
                    taxistop=1;
                }
            }
        }
    }
    if(pos().y() <400)//during jump shoot bullet
    {
        if(event->key() == Qt::Key_A)
        {
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+50,y());
            scene->addItem(bullet);
            if(bulletsound->state()==QMediaPlayer::PlayingState)
            {
                bulletsound->setPosition(0);
            }
            else if(bulletsound->state()==QMediaPlayer::StoppedState)
            {
                bulletsound->play();
            }
        }
    }

}

void Taxi::move()
{ 
    if(up_down == 1)
    {
        light->setPos(light->x(),light->y()-20);
        setPos(x(),y()-20);
        if(pos().y() < 100)
            up_down=0;
    }
    else if(up_down == 0)
    {
        light->setPos(light->x(),light->y()+20);
        setPos(x(),y()+20);
        if(pos().y() == 315)
        {
            up_down=2;
            taxistop=0;
        }

    }
}

void Taxi::moveend()
{
    setPos(x()+6,y());
    light->setPos(light->x()+6,light->y());
    if(pos().x()+100>740)
    {
        game->stop_all();
        musicend->play();
        ending = new Gamescene(4);
        connect(ending,SIGNAL(theend()),this,SLOT(theend()));
        scene->addItem(ending);
        ending->setFlag(QGraphicsItem::ItemIsFocusable);
        ending->setFocus();
    }
}

void Taxi::theend()
{
    delete ending;
    emit endingsignal();
}

