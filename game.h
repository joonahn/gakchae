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
#include "light.h"
#include "gray_bar.h"
#include "color_bar.h"
#include "mini_image.h"
#include "gameinfo.h"

class Game: public QGraphicsView{
public:
       Game(QGraphicsScene * _scene, int before_money, int resttime);
       void countup();
       void decrease_count();
       void decrease_time();
       QGraphicsScene * scene;
       Taxi * taxi;
       Summoner * summoner;
       Money * money;
       Taxi_distance * taxi_distance;
       Light * light;
       gray_Bar * gray;
       color_Bar * red;
       Mini_image* mini[7];
       QTimer * timer;
       QTimer * Final_timer;
       QMediaPlayer * music;
       Gameinfo* info;
       int getFinalmoney();
       int getFinaltime();

private:
       int count;
       int Final_money;
       int Final_time;
};



#endif // GAME_H

