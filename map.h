#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "character.h"
#include "tile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapdata.h"
#include "menustrip.h"

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

    //Frame move Timer
    QTimer * timer;

    //Stage Variable
    int stage;

    //insolzas' roomnum
    int insol[3];

    int insol2pwd;

    bool insol2found;

public:
    Map(QMainWindow * _mainwindow,QWidget *parent);
    Character * getCharacter();
    Tile * getTile(int x, int y);
    SJW * getJunwi(int index);

    void changeStage();
    void finishRC();
    void placeObject();
    void keyboardInput(QKeyEvent * event);
    int getPasswd();
    Menustrip * getMenu();

public slots:
    void moveall();
    void reset();
signals:
};

#endif // MAP_H

