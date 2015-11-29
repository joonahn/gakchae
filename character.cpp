#include "character.h"

Character::Character()
{

}

Character::Character(QWidget *parent, Map *_map):QLabel(parent),map(_map),velocity(1.0){
    this->setGeometry(0,0,50,50);
    this->setPixmap("saenaegi.jpg");
}


bool Character::conflicted(){
    return false;
}


void Character::move_left(){
    this->setGeometry(this->x()+velocity,this->y(),50,50);
}
void Character::move_up(){
    this->setGeometry(this->x(),this->y()-velocity,50,50);
}
void Character::move_down(){
    this->setGeometry(this->x(),this->y()+velocity,50,50);
}
void Character::move_right(){
    this->setGeometry(this->x()-velocity,this->y(),50,50);
}
