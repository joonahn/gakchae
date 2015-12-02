#include "character.h"
#include "map.h"


Character::Character(QWidget *parent, Map *_map,int _velocity,int _y,int _x):QLabel(parent),map(_map),velocity(_velocity),x(_x),y(_y),movingdir(NONE){
    QPixmap pixmap(":/images/saenaegi.png");
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
    case UP:
        return y/50==0||map->getTile(x/50,y/50-1)->canpass();
    case DOWN:
        return y/50==19||map->getTile(x/50,y/50+1)->canpass();
    case LEFT:
        return x/50==0||map->getTile(x/50-1,y/50)->canpass();
    case RIGHT:
        return x/50==69||map->getTile(x/50+1,y/50)->canpass();
    case NONE:
        return true;
    }
    return false;
}


void Character::changedir(DIRECTION _dir){
    movingdir=_dir;
}

void Character::move(){
    SJW* junwi;
    if(x%50!=0||y%50!=0||!conflicted())
        switch(movingdir){
        case UP:
            y-=velocity;
            if(50-(y%50)<velocity){
                y+=50-(y%50);
                movingdir=NONE;
            }
            break;
        case DOWN:
            y+=velocity;
            if(y%50<velocity){
                y-=y%50;
                movingdir=NONE;
            }
            break;
        case LEFT:
            x-=velocity;
            if(50-(x%50)<velocity){
                x+=50-(x%50);
                movingdir=NONE;
            }
            break;
        case RIGHT:
            x+=velocity;
            if((25+x)%50<velocity){
                x-=(25+x)%50;
                movingdir=NONE;
            }
            break;
        }
    for(int i=0;i<6;i++){
        junwi=map->getJunwi(i);
        if((x+25)/50==(junwi->getx()+25)/50&&(y+25)/50==(junwi->gety()+25)/50){
            emit catched();
            break;
        }
    }
}

void Character::setx(int _x){
    x=_x;
}

void Character::sety(int _y)
{
    y=_y;
}

SJW::SJW(QWidget* parent,Map* _map,int _x,int _y,DIRECTION _dir):Character(parent,_map,3,_x,_y){
    changedir(_dir);
}

void SJW::moveSJW(){
    if(seeked()!=NONE){
        changedir(seeked());
    }
    else if(conflicted()){
        switch(Character::movingdir){
        case UP:
            changedir(DOWN);
            break;
        case DOWN:
            changedir(UP);
            break;
        case LEFT:
            changedir(RIGHT);
            break;
        case RIGHT:
            changedir(LEFT);
            break;
        }
    }
    move();
}

DIRECTION SJW::seeked(){
    Tile* tmp=map->getTile(getx()/50,gety()/50);
    Tile* charTile=map->getTile(map->getCharacter()->getx()/50,map->getCharacter()->gety()/50);
    if(getx()%50!=0||gety()%50!=0)
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


