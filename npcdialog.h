#ifndef NPCDIALOG_H
#define NPCDIALOG_H

#include "tile.h"
#include "minigame.h"

class Map;

//typedef enum{INSOL1,INSOL2,INSOL3,FRIEND,EMPTY,TRAP}ROOMTYPE;

class Npcdialog : public QLabel
{
    Q_OBJECT
private:
    //Private members
    Map * map;
    Room * room;
    int nselect;
    int currentindex;
    int currentchoice;
    bool unlocked;

    //Labels
    QLabel * NPCname;
    QLabel * NPCimage;
    QLabel * dialoglabel;
    QLabel * dialogtextlabel;
    QLabel * dialogselectlabel[2];
    QLabel * inputpwlabel[4];
    QString inputpw;

    //Minigame view
    minigame::Game * game;

    //Private Function
    //~Dialog : setUI, ~DialogSelect : do next action by choice
    void insol1Dialog(int index);
    void insol1DialogSelect(int index, int choice);
    void insol2DIalog(int index);
    void insol2DialogSelect(int index, int choice);
    void friendDialog(int index);
    void friendDialogSelect(int index, int choice);

    //EmptyDialogSelect, TrapDialogSelect : called if any key was pressed
    void emptyDialog();
    void emptyDialogSelect();
    void trapDialog();
    void trapDialogSelect();
    void passwdDialog();
    void passwdDialogSelect(int choice);
    void closeDialog();

    //UIFunction
    void setLabelTextColor(QLabel * label);

signals:
    void resumeGame();
    void reset();
    void message();

public:
    //Constructor
    Npcdialog(QWidget * parent, Room * _room);

    //Keyboard Input Method
    void keyPressEvent(QKeyEvent * event);

    //Place UI *** need to be called when dialog, select text changed ***
    void refreshUI();

    bool isTrap();
public slots:
    //Public methods
    void succeeded();
    void failed();
};

#endif // NPCDIALOG_H

