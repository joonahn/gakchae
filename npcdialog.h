#ifndef NPCDIALOG_H
#define NPCDIALOG_H

#include "tile.h"

//typedef enum{INSOL1,INSOL2,INSOL3,FRIEND,EMPTY,TRAP}ROOMTYPE;

class Npcdialog : public QLabel
{
    Q_OBJECT
private:
    Room * room;
    int nselect;
    bool locked;
    QLabel * NPCimage;
    QLabel * dialoglabel;
    QLabel * dialogtextlabel;
    QLabel * dialogselectlabel[2];
    QLabel * buttons[12];
    QLabel * inputpw[4];

public:
    //Constructor
    Npcdialog(QWidget * parent, Room * _room);

    //Keyboard Input Method
    void keyboardInput(QKeyEvent * event);

    //Place UI *** need to be called when dialog, select text changed ***
    void refreshUI();
    void changeDialogToUnlocked();
};

#endif // NPCDIALOG_H

