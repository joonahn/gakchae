#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include "character.h"
#include "tile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Tile;
class Character;
class SJW;


enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

class Map : public QWidget
{
private:
    Character * me;
    SJW * junwis[6];
    Tile * mapData[20][70];
    Ui::MainWindow * mainwindow;
public:
    Map(QMainWindow * _mainwindow);
    Character * getCharacter();
    Tile * getTile(int x, int y);
    void placeObject();
    void keyboardInput(QKeyEvent * event);
};

#endif // MAP_H

