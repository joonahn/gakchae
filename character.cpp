#include "character.h"


Character::Character(QWidget *parent, Map *_map,int _velocity,int _x,int _y):QLabel(parent),map(_map),velocity(_velocity){
    this->setGeometry(0,0,50,50);
    this->setPixmap("saenaegi.jpg");
}

int Character::getx(){
   return x;
}

int Character::gety(){
    return y;
}

bool Character::conflicted(){
    if(x%50==25&&y%50==25)
        return true;
    switch(movinigdir){
    UP:
        return y/50==0||map->getTile(x/50,y/50-1)->canpass();
    DOWN:
        return y/50==19||map->getTile(x/50,y/50+1)->canpass();
    LEFT:
        return x/50==0||map->getTile(x/50-1,y/50)->canpass();
    RIGHT:
        return x/50==99||map->getTile(x/50+1,y/50)->canpass();
    NONE:
        return true;
    }
}


bool Character::changedir(DIRECTION _dir){
    movingdir=_dir;
}

void Character::move(){
    if(x%50!=25||y%50!=25||!conflicted()){
        switch(movingdir){
        UP:
            y-=velocity;
            if((25-y)%50<velocity)
                y+=(25-y)%50;
            break;
        DOWN:
            y+=velocity;
            if((25+y)%50<velocity)
                y-=(25+y)%50;
            break;
        LEFT:
            x-=velocity;
            if((25-x)%50<velocity)
                x+=(25-x)%50;
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

SJW::SJW(QWidget* parent,Map* _map,int _x,int _y):Character(parent,_map,2,_x,_y),seeked(false){
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
    Tile* tmp=map->getTile(x/50,y/50),charTile=map->getTile(map->getCharacter()->x()/50,map->getCharacter()->y()/50);
    if(x%50!=25||y%50!=25)
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
