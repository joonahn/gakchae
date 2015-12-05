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
    case stairs:
        pixmap=new QPixmap(":/images/stairs.png");
        break;
    case door:
        //do sth
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

Room::Room(QWidget *parent, Map *_map, TileType _type, int _x, int _y, int _roomnum, ROOMTYPE _rtype, int _passwd):Tile(parent,_map,_type,_x,_y),roomnum(_roomnum),rtype(_rtype),passwd(_passwd)
{
    QImage *image;
    switch(gettype()){
    case rup:
        image=new QImage(":/images/rup.png");
        break;
    case rdown:
        image=new QImage(":/images/rdown.png");
        break;
    case rleft:
        image=new QImage(":/images/rleft.png");
        break;
    case rright:
        image=new QImage(":/images/rright.png");
        break;
    }
    QPainter* painter = new QPainter(image);
    if(rtype<3)
        painter->setPen(Qt::red);
    else
        painter->setPen(Qt::blue);
    painter->setFont(QFont("Arial",3));
    painter->drawText(image->rect(),Qt::AlignCenter,QString::number(roomnum));
    this->setPixmap(QPixmap::fromImage(*image));
    if(rtype==FRIEND){
        myfriend=new FRIENDS;
        myfriend->friendtype=rand()%3;
        myfriend->money=(rand()%31)*100+1000;
        if(passwd!=0)
            myfriend->money+=10000;
    }
}

int Room::open()
{
    return passwd;
}

bool Room::isClosed()
{
    return passwd!=0;
}

FRIENDS *Room::getfriend()
{
    return myfriend;
}

ROOMTYPE Room::getroomtype()
{
    return rtype;
}

void Room::deletefriend()
{
    delete myfriend;
    myfriend=NULL;
    rtype=EMPTY;
}


