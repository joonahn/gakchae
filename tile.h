#ifndef TILE_H
#define TILE_H

#include<iostream>
#include<QLabel>
#include<QWidget>
#include"mapdata.h"

class Map;

typedef enum{UP,DOWN,LEFT,RIGHT,NONE}DIRECTION;

typedef enum{INSOL1,INSOL2,INSOL3,CLOSED,FRIEND,EMPTY,TRAP}ROOMTYPE;

class Tile:public QLabel{
private:
    TileType type;
    Map* map;
    int x,y;
public:
    Tile(QWidget* parent,Map* _map,TileType _type,int _x,int _y);
    TileType gettype();
    bool canpass();
    Tile* getDownTile();
    Tile* getUpTile();
    Tile* getLeftTile();
    Tile* getRightTile();
    int getx();
    int gety();
};

class Room:public Tile{
private:
    int roomnum;
    ROOMTYPE rtype;
    int passwd;
};



#endif // TILE

