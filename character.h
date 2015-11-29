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
    float velocity;
    Map* map;
    Tile* tile;
    int x,y;

public:
    Character();
    Character(QWidget* parent,Map* _map);
    void set_tile();
    Tile* get_tile();
    int getx();
    int gety();

signals:
    QLabel* conflicted();

public slots:
    void move_left();
    void move_up();
    void move_down();
    void move_right();
};

class Saejunwi:public Character{
signals:
    bool seeked;
public:
    void setseeked();
public slots:
    void follow();
    void dopattern();
}

#endif // CHARACTER_H
