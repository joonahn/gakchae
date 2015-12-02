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
    int x,y;
    DIRECTION movingdir;

public:
    Character(QWidget* parent,Map* _map,int _velocity,int _y,int _x);
    int getx();
    int gety();
    bool conflicted();
    void changedir(DIRECTION _dir);
    void move();
};

class SJW:public Character{
public:
    SJW(QWidget* parent,Map* _map,int _x,int _y,DIRECTION _dir);
    void moveSJW();
signals:
    DIRECTION seeked();
    bool catched();
};

#endif // CHARACTER_H
