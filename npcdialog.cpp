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
    locked = room->isClosed();

    //typedef enum{INSOL1,INSOL2,INSOL3,FRIEND,EMPTY,TRAP}ROOMTYPE;
    ROOMTYPE roomtype = room->getroomtype();
    QPixmap * pixmap;
    switch(roomtype)
    {
    case INSOL1:
        pixmap = QPixmap(":/images/room.png");
        this->setPixmap(pixmap);
        delete pixmap;
        pixmap = QPixmap(":/images/");
        break;
    }
}
