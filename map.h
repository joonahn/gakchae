#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>
#include "character.h"

class Tile;



enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

class Map : public QWidget
{
private:
    Character * me;
    Saejunwi * junwis[6];
    Tile * mapData[][];
public:
    Map(stage _stage);
    Character * getCharacter();
    void placeObject();
};

#endif // MAP_H

