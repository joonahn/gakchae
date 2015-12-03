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
    Q_OBJECT
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
    void changedir(DIRECTION _dir);
    void move();
    void setx(int _x);
    void sety(int _y);
signals:
    void catched();
};

class SJW:public Character{
public:
    SJW(QWidget* parent,Map* _map,int _x,int _y,DIRECTION _dir);
    void moveSJW();
private:
    DIRECTION seeked();
};

#endif // CHARACTER_H
