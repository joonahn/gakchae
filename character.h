#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<QWidget>
#include<QImage>
#include<QTimer>
#include<QPixmap>
#include<QLabel>
#include"tile.h"

class Map;

class Character:public QLabel{
protected:
    int velocity;
    Map* map;
    Tile* tile;
    int x,y;
    DIRECTION movingdir;

public:
    Character();
    Character(QWidget* parent,Map* _map,int _velocity);
    void set_tile();
    Tile* get_tile();
    int getx();
    int gety();
    bool changedir(DIRECTION _dir);

public slots:
    void move();
};

class Saejunwi:public Character{
signals:
    bool seeked;
public:
    Saejunwi(int _x,int _y);
    void setseeked();
    void follow();
    void dopattern();
signals:
    bool catched();
};

#endif // CHARACTER_H
