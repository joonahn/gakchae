#include "npcdialog.h"

Npcdialog::Npcdialog(QWidget *parent, Room *_room) : QLabel(parent)
{
    //Create Labels
    NPCimage = new QLabel(this);
    dialoglabel = new QLabel(this);
    dialogtextlabel = new QLabel(this);
    dialogselectlabel[0] = new QLabel(this);
    dialogselectlabel[1] = new QLabel(this);

    //Set Inner variables
    room = _room;
}
