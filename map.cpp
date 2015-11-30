#include "map.h"
#include "mapdata.h"

Map::Map(MainWindow *_mainwindow)
{
    //Initialize & Load RC1 stage
    mainwindow = _mainwindow;

    //in pixel coordination
    me = new Character(this, this, 350, 750, 0);

    //Initial Junwi Position Needed, in pixel coordination
    junwis[0] = new SJW(this, this, 350,150,DOWN);
    junwis[1] = new SJW(this, this, 2950,350,DOWN);
    junwis[2] = new SJW(this, this, 1250,800,LEFT);
    junwis[3] = new SJW(this, this, 1300,300, RIGHT);
    junwis[4] = new SJW(this, this, 1850,300, UP);
    junwis[5] = new SJW(this, this, 3050,200, RIGHT);

    //Initialize Tiles
    for(int i = 0;i<20;i++)
        for(int j = 0;j<100;j++)
        {
            /*j is X axis coordination, i is j axis coordination */
            mapData[i][j] = new Tile(this, rc1_mapdata[i][j], i, j);
        }
}

Character *Map::getCharacter()
{
    return me;
}

Tile *Map::getTile(int x, int y)
{
    return mapData[y][x];
}

void Map::placeObject()
{
    me->setGeometry((740-50)/2, (515-50)/2, 50, 50);
    for(int i = 0;i<20;i++)
        for(int j = 0;J,100;j++)
        {
            mapData[i][j]->setGeometry(mapData[i][j]->getx()*50 - me->getx() + ((740-50/2)),
                                       mapData[i][j]->gety()*50 - me->gety() + ((515-50)/2), 50, 50);
        }
    for(int i = 0;i<6;i++)
    {
        junwis[i]->setGeometry(junwis[i]->getx()*50 - me->getx() + ((740-50/2)),
                               junwis[i]->gety()*50 - me->gety() + ((515-50)/2), 50, 50);
    }

}

