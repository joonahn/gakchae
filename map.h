#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QWidget>

class Tile;

class Map : public QWidget
{
private:
    int posX, posY;
    Tile * mapData[][];
public:
    Map(int position);
    bool move_left();
    bool move_right();
    bool move_up();\
    bool move_down();
};

#endif // MAP_H

