#ifndef GAME_H
#define GAME_H


#include <Qwidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "taxi.h"
#include "building.h"
#include "summoner.h"
#include "money.h"
#include "taxi_distance.h"
#include "bar.h"
#include "mini_image.h"
#include "gamescene.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
       Game(QWidget* parent, int before_money, int resttime);
       void countup();
       void decrease_count();
       void stop_all();
       QGraphicsScene * scene;
       Taxi * taxi;
       Summoner * summoner;
       Money * money;
       Taxi_distance * taxi_distance;
       Bar * gray;
       Bar * red;
       Mini_image* mini[7];
       QTimer * timer;
       QMediaPlayer * music;
       Gamescene* info;
       Gamescene *gameover2;
       Gamescene *background;
       QMediaPlayer * gameover2_bgm;

       int getFinalmoney();
       int getFinaltime();
       void decrease_Finaltime(int time);
private:
       int count;
       int Final_money;
       int Final_time;
public slots:
       void theend();
signals:
       void ending();
};



#endif // GAME_H

