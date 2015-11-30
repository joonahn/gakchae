#include "character.h"


Character::Character(QWidget *parent, Map *_map,int _velocity,int _x,int _y):QLabel(parent),map(_map),velocity(_velocity),x(_x),y(_y){
    QPixmap pixmap(":/images/asdfasdf.png");
    this->setPixmap(pixmap);
}

int Character::getx(){
   return x;
}

int Character::gety(){
    return y;
}

bool Character::conflicted(){
    if(x%50!=0||y%50!=0)
        return false;
    switch(movingdir){
    UP:
        return y/50==0||map->getTile(x/50,y/50-1)->canpass();
    DOWN:
        return y/50==19||map->getTile(x/50,y/50+1)->canpass();
    LEFT:
        return x/50==0||map->getTile(x/50-1,y/50)->canpass();
    RIGHT:
        return x/50==69||map->getTile(x/50+1,y/50)->canpass();
    NONE:
        return true;
    }
}


bool Character::changedir(DIRECTION _dir){
    movingdir=_dir;
}

void Character::move(){
    if(x%50!=0||y%50!=0||!conflicted()){
        switch(movingdir){
        UP:
            y-=velocity;
            if(50-(y%50)<velocity)
                y+=50-(y%50);
            break;
        DOWN:
            y+=velocity;
            if(y%50<velocity)
                y-=y%50;
            break;
        LEFT:
            x-=velocity;
            if(50-(x%50)<velocity)
                x+=50-(x%50);
            break;
        RIGHT:
            x+=velocity;
            if((25+x)%50<velocity)
                x-=(25+x)%50;
            break;
        }
    }
    else
        movingdir=NONE;
}

SJW::SJW(QWidget* parent,Map* _map,int _x,int _y,DIRECTION _dir):Character(parent,_map,2,_x,_y),movingdir(_dir){
}

void SJW::moveSJW(){
    if(seeked()!=NONE){
        movingdir=seeked();
    }
    else if(conflicted()){
        switch(movingdir){
        case UP:
            movingdir=DOWN;
            break;
        case DOWN:
            movingdir=UP;
            break;
        case LEFT:
            movingdir=RIGHT;
            break;
        case RIGHT:
            movingdir=LEFT;
            break;
        }
    }
    move();
}

DIRECTION SJW::seeked(){
    Tile* tmp=map->getTile(x/50,y/50);
    Tile* charTile=map->getTile(map->getCharacter()->x()/50,map->getCharacter()->y()/50);
    if(x%50!=0||y%50!=0)
        return NONE;
    if(tmp->getx()==charTile->getx()){
        if(tmp->gety()<charTile->gety())
            while(tmp->canpass()){
                tmp=tmp->getDownTile();
                if(tmp==charTile)
                    return DOWN;
            }
        else
            while(tmp->canpass()){
                tmp=tmp->getUpTile();
                if(tmp==charTile)
                    return UP;
            }
    }
    else if(tmp->gety()==charTile->gety()){
        if(tmp->getx()<charTile->gety())
            while(tmp->canpass()){
                tmp=tmp->getRightTile();
                if(tmp==charTile)
                    return RIGHT;
            }
        else
            while(tmp->canpass()){
                tmp=tmp->getLeftTile();
                if(tmp==charTile)
                    return LEFT;
            }
    }
    return NONE;
}

bool SJW::catched(){
    return (x+25)/50==(map->getCharacter()->x()+25)/50&&(y+25)/50==(map->getCharacter()->y()+25)/50;
}


