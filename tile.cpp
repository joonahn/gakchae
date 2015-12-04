#include"tile.h"
#include"map.h"

Tile::Tile(QWidget* parent,Map* _map,TileType _type,int _x,int _y):QLabel(parent),map(_map),type(_type),x(_x),y(_y){
    QPixmap* pixmap;
    switch(type){
    case rup:
        pixmap=new QPixmap(":/images/rup.png");
        break;
    case rdown:
        pixmap=new QPixmap(":/images/rdown.png");
        break;
    case rleft:
        pixmap=new QPixmap(":/images/rleft.png");
        break;
    case rright:
        pixmap=new QPixmap(":/images/rright.png");
        break;
    case rfloor:
        pixmap=new QPixmap(":/images/floor.png");
        break;
    case pot1:
        pixmap=new QPixmap(":/images/pot1.png");
        break;
    case pot2:
        pixmap=new QPixmap(":/images/pot2.png");
        break;
    case rfill:
        pixmap=new QPixmap(":/images/rfill.png");
        break;
    case downstairs:
    case upstairs:
        pixmap=new QPixmap(":/images/stairs.png");
        break;
    }
    this->setPixmap(*pixmap);
    delete pixmap;
}

TileType Tile::gettype(){
    return type;
}

bool Tile::canpass(){
    return (type==rfloor);
}

Tile* Tile::getDownTile(){
    if(y==69)
        return NULL;
    return map->getTile(x,y+1);
}

Tile* Tile::getUpTile(){
    if(y==0)
        return NULL;
    return map->getTile(x,y-1);
}

Tile* Tile::getLeftTile(){
    if(x==0)
        return NULL;
    return map->getTile(x-1,y);
}

Tile* Tile::getRightTile(){
    if(x==19)
        return NULL;
    return map->getTile(x+1,y);
}

int Tile::getx(){
    return x;
}

int Tile::gety(){
    return y;
}

int Tile::open()
{
    return -1;
}

Room::Room(QWidget *parent, Map *_map, TileType _type, int _x, int _y, int _roomnum, ROOMTYPE _rtype, int _passwd,FRIENDS* _myfriend):Tile(parent,_map,_type,_x,_y),roomnum(_roomnum),rtype(_rtype),passwd(_passwd)
{
    myfriend=new FRIENDS;
    myfriend->money=_myfriend->money;
    myfriend->sleep=_myfriend->sleep;
    closed=passwd!=0;
    cleared=false;
    this->setText(QString::number(roomnum));
}

int Room::open()
{
    return passwd;
}

bool Room::isClosed()
{
    return closed;
}

bool Room::isStoryFinished()
{
    return cleared;
}

FRIENDS *Room::getfriend()
{
    return myfriend;
}

