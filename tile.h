#ifndef TILE_H
#define TILE_H

#include<iostream>
#include<QLabel>
#include<QWidget>
#include<QImage>
#include<QPainter>
#include<cstdlib>
#include"mapdata.h"

class Map;

typedef enum{UP,DOWN,LEFT,RIGHT,NONE}DIRECTION;

typedef enum{INSOL1,INSOL2,INSOL3,FRIEND,EMPTY,TRAP}ROOMTYPE;

typedef struct friends{
    //0 : sleep,1 : go,2 : don't go
    int friendtype;
    int money;
}FRIENDS;

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
    virtual int open();
};

class Room:public Tile{
private:
    int roomnum;
    ROOMTYPE rtype;
    int passwd;
    FRIENDS* myfriend;
    QLabel* roomnumlabel;
public:
    Room(QWidget* parent,Map* _map,TileType _type,int _x,int _y,int _roomnum,ROOMTYPE _rtype,int _passwd);
    int open();
    bool isClosed();
    FRIENDS* getfriend();
    ROOMTYPE getroomtype();
    void deletefriend();
};


#endif // TILE

