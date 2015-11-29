#ifndef TILE_H
#define TILE_H

#include<iostream>
#include<QLabel>
#include<QWidget>

class Map;

class Tile:public QLabel{
private:
    TILETYPE type;
    Map* map;

public:
    Tile(Map* _parent,TILETYPE _type):parent(_parent),type(_type){};
    virtual void draw();
    void gettype();
    bool canpass();
};

class Room:public Tile{
private:
    DIRECTION dir;
    bool closed;
    unsigned roomnum;
public:
    Room(Map* parent,DIRECTION _dir,unsigned roomnum):Tile(parent,ROOM),dir(_dir),roomnum(_roomnum){};
    void draw();
    void canopen();
    unsigned getroomnum();
};

class NPC:public Tile{
private:
};

#endif // TILE

