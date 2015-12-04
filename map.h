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

    //0 for nothing, 1 for checking insol2, 2 for find insol1, 3 for clear insol2
    int story;
    int friendnum;

    int insol2pwd;

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
    int getstory();
    void nextstory();

public slots:
    void moveall();
    void reset();
    void resume();
signals:
};

#endif // MAP_H

