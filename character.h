#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<QWidget>
#include<QImage>
#include<QTimer>
#include<QPixmap>
#include<QLabel>
#include"tile.h"
#include"map.h"

class Character:public QLabel{
protected:
    int velocity;
    Map* map;
    int x,y;
    DIRECTION movingdir;

public:
    Character(QWidget* parent,Map* _map,int _velocity,int _x,int _y);
    int getx();
    int gety();
    bool conflicted();
    bool changedir(DIRECTION _dir);
    void move();
};

class Saejunwi:public Character{
public:
    Saejunwi(QWidget* parent,Map* _map,int _x,int _y);
    void follow();
    void dopattern();
signals:
    bool seeked();
    bool catched();
};

#endif // CHARACTER_H
