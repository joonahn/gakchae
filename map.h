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



enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

class Map : public QWidget
{
Q_OBJECT
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
    SJW * getJunwi(int index);
    void keyboardInput(QKeyEvent * event);
public slots:
    void moveall();
    void reset();
signals:
};

#endif // MAP_H

