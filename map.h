#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>
#include <QTimer>
#include "character.h"
#include "tile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapdata.h"



enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

class Map : public QWidget
{
private:
    Character * me;
    SJW * junwis[6];
    Tile * mapData[20][70];
    Ui::MainWindow * mainwindow;
    QTimer * timer;
public:
    Map(QMainWindow * _mainwindow,QWidget *parent);
    Character * getCharacter();
    Tile * getTile(int x, int y);
    void placeObject();
<<<<<<< HEAD
    void keyboardInput(QKeyEvent * event);
=======
    SJW * getJunwi(int index);
public slots:
    void moveall();
    void reset();
signals:
>>>>>>> 1cfb319dd70592b32ec6526704595312b6648795
};

#endif // MAP_H

