#include "character.h"

Character::Character()
{

}

Character::Character(QWidget *parent, Map *_map,int _velocity):QLabel(parent),map(_map),velocity(_velocity){
    this->setGeometry(0,0,50,50);
    this->setPixmap("saenaegi.jpg");
}


bool Character::conflicted(){
    return false;
}



bool Character::move_left(){
    this->setGeometry(this->x()+velocity,this->y(),50,50);
}

bool Character::move_up(){
    this->setGeometry(this->x(),this->y()-velocity,50,50);
}

bool Character::move_down(){
    this->setGeometry(this->x(),this->y()+velocity,50,50);
}

bool Character::move_right(){
    this->setGeometry(this->x()-velocity,this->y(),50,50);
}
