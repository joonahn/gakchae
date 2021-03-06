﻿#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QBrush>
#include <QGraphicsScene>
#include <QMediaPlayer>

#include "character.h"
#include "tile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapdata.h"
#include "menustrip.h"
#include "npcdialog.h"
#include "message.h"
#include "game.h"
#include "score.h"

enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

class Map : public QWidget
{
Q_OBJECT
private:
    //Character Objects
    Character * me;
    SJW * junwis[6];

    //mapData : RC 2nd Floor, mapData2 : RC 1st Floor
    Tile * mapData[20][70];
    Tile * mapData2[20][70];

    //MenuStrip
    Menustrip * menu;

    //MainWindow
    Ui::MainWindow * mainwindow;

    //Npcdialog
    Npcdialog* npcdialog;

    //Frame move Timer
    QTimer * timer;

    Message * message;
    //create main_bgm
    QMediaPlayer *main_bgm;
    QTimer * musictimer;
    //Stage Variable
    int stage;

    //insolzas' roomnum
    int insol[3];

    //-5 for start, 0 for nothing, 1 for checking insol2, 2 for find insol1, 3 for clear insol2
    int story;
    int friendnum;

    int insol2pwd;

    score* Score;
public:
    Map(QMainWindow * _mainwindow,QWidget *parent);
    Character * getCharacter();
    Tile * getTile(int x, int y);
    SJW * getJunwi(int index);

    void changeStage();
    void finishRC();
    void placeObject();
    void keyPressEvent(QKeyEvent * event);
    int getPasswd();
    Menustrip * getMenu();
    int getstory();
    void nextstory();
    void callmessage2();
    Ui::MainWindow *getWindow();

public slots:
    void reset();
    void moveall();
    void caught();
    void resume();
    void messageend();
    void gameover();
    void highscore();
    void bgmcheck();

signals:
};

#endif // MAP_H

