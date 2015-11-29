#include "character.h"

Character::Character()
{

}

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
    switch(movinigdir){
    UP:
        return y/50==0||map->getTile(x/50,y/50-1)->canpass();
    DOWN:
        return y/50==19||map->getTile(x/50,y/50+1)->canpass();
    LEFT:
        return x/50==0||map->getTile(x/50-1,y/50)->canpass();
    RIGHT:
        return x/50==99||map->getTile(x/50+1,y/50)->canpass();
    }
}


bool Character::changedir(DIRECTION _dir){
    movingdir=_dir;
}

void Character::move(){
    if(!conflicted())
        switch(movingdir){
        UP:
            y-=velocity;
            break;
        DOWN:
            y+=velocity;
            break;
        LEFT:
            x-=velocity;
            break;
        RIGHT:
            x+=velocity;
            break;
        }
}

Saejunwi::Saejunwi(QWidget* parent,Map* _map,int _x,int _y):Character(parent,_map,2,_x,_y),seeked(false){
}

void setseeked();
void follow();
void dopattern();
