#include "character.h"
#include "map.h"


Character::Character(QWidget *parent, Map *_map,int _velocity,int _x,int _y):QLabel(parent),map(_map),velocity(_velocity),x(_x),y(_y),movingdir(NONE){
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
        return y/50==0||!map->getTile(x/50,y/50-1)->canpass();
    case DOWN:
        return y/50==19||!map->getTile(x/50,y/50+1)->canpass();
    case LEFT:
        return x/50==0||!map->getTile(x/50-1,y/50)->canpass();
    case RIGHT:
        return x/50==69||!map->getTile(x/50+1,y/50)->canpass();
    case NONE:
        return true;
    }
    return false;
}


void Character::changedir(DIRECTION _dir){
    if(x%50==0&&y%50==0)
        movingdir=_dir;
}

void Character::move(){
    if(x%50!=0||y%50!=0||!conflicted())
        switch(movingdir){
        case UP:
            y-=velocity;
            if(-(50-y)%50<velocity){
                y+=(50-y)%50;
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
            if(-(50-x)%50<velocity){
                x+=(50-x)%50;
                movingdir=NONE;
            }
            break;
        case RIGHT:
            x+=velocity;
            if(x%50<velocity){
                x-=x%50;
                movingdir=NONE;
            }
            break;
        }
}

void Character::setx(int _x){
    x=_x;
}

void Character::sety(int _y)
{
    y=_y;
}

void Character::check()
{
    SJW* junwi;
    for(int i=0;i<6;i++){
        junwi=map->getJunwi(i);
        if(((x+25)/50==(junwi->getx()+25)/50)&&((y+25)/50)==((junwi->gety()+25)/50)){
            emit catched();
            break;
        }
    }
}

Tile *Character::getspacebar()
{
    Tile* tmp;
    if(x%50!=0||y%50!=0)
        return NULL;
    switch(movingdir){
    case UP:
        tmp=map->getTile(x/50,y/50-1);
        if(tmp->gettype()==rdown||tmp->gettype()>7)
            return tmp;
        else
            return NULL;
    case DOWN:
        tmp=map->getTile(x/50,y/50+1);
        if(tmp->gettype()==rup||tmp->gettype()>7)
            return tmp;
        else
            return NULL;
    case LEFT:
        tmp=map->getTile(x/50-1,y/50);
        if(tmp->gettype()==rright||tmp->gettype()>7)
            return tmp;
        else
            return NULL;
    case RIGHT:
        tmp=map->getTile(x/50+1,y/50);
        if(tmp->gettype()==rleft||tmp->gettype()>7)
            return tmp;
        else
            return NULL;
    default:
        return NULL;
    }
}

SJW::SJW(QWidget* parent,Map* _map,int _x,int _y,DIRECTION _dir,int num):Character(parent,_map,3,_x,_y){
    QPixmap * pixmap;
    switch(num){
    case 0:
        pixmap=new QPixmap(":/images/saejunwee.png");
        break;
    case 1:
        pixmap=new QPixmap(":/images/saejunwee2.png");
        break;
    case 2:
        pixmap=new QPixmap(":/images/saejunwee3.png");
        break;
    }
    this->setPixmap(*pixmap);
    changedir(_dir);
}

void SJW::moveSJW(){
    DIRECTION seek=seeked();
    if(seek!=NONE&&getx()%50==0&&gety()%50==0){
        changedir(seek);
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
    if(x%50!=0||y%50!=0||!conflicted())
        switch(movingdir){
        case UP:
            y-=velocity;
            if(-(50-y)%50<velocity){
                y+=(50-y)%50;
            }
            break;
        case DOWN:
            y+=velocity;
            if(y%50<velocity){
                y-=y%50;
            }
            break;
        case LEFT:
            x-=velocity;
            if(-(50-x)%50<velocity){
                x+=(50-x)%50;
            }
            break;
        case RIGHT:
            x+=velocity;
            if(x%50<velocity){
                x-=x%50;
            }
            break;
        }
}

DIRECTION SJW::seeked(){
    int tx,ty,cx,cy;
    tx=getx()/50;
    ty=gety()/50;
    cx=(map->getCharacter()->getx()+25)/50;
    cy=(map->getCharacter()->gety()+25)/50;
    if(getx()%50!=0||gety()%50!=0)
        return NONE;
    if(tx==cx){
        int i=ty;
        if(ty<cy)
            while(map->getTile(cx,i)->canpass()){
                i++;
                if(i==cy)
                    return DOWN;
                if(i==19)
                    break;
            }
        else
            while(map->getTile(cx,i)->canpass()){
                i--;
                if(i==cy)
                    return UP;
                if(i==0)
                    break;
            }
    }
    else if(ty==cy){
        int i=tx;
        if(tx<cx)
            while(map->getTile(i,cy)->canpass()){
                i++;
                if(i==cx)
                    return RIGHT;
                if(i==69)
                    break;
            }
        else
            while(map->getTile(i,cy)->canpass()){
                i--;
                if(i==cx)
                    return LEFT;
                if(i==0)
                    break;
            }
    }
    return NONE;
}


