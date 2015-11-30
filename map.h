#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>
#include "character.h"
#include "tile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Tile;



enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

class Map : public QWidget
{
private:
    Character * me;
    Saejunwi * junwis[6];
    Tile * mapData[20][70];
    Ui::MainWindow * mainwindow;
public:
    Map(Ui::MainWindow * _mainwindow);
    Character * getCharacter();
    Tile * getTile(int x, int y);
    void placeObject();
};

#endif // MAP_H

