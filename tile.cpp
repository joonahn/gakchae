#include"tile.h"

Tile(Map* _parent,TILETYPE _type,int _x,int _y);
void gettype();
bool canpass();
Tile* getDownTile();
Tile* getUpTile();
Tile* getLeftTile();
Tile* getRightTile();
int getx();
int gety();
