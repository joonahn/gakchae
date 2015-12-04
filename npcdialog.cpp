#include "npcdialog.h"

void Npcdialog::insol1Dialog(int index)
{
    QPixmap * pixmap;
    if(index==1)
    {
        //if(!map->isInsol2visited()) {insol1DialogSelect(5);return;}
        pixmap = new QPixmap(":/images/room.png");
        this->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/insolja.png");
        NPCimage->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/blacksquare.png");
        dialoglabel->setPixmap(*pixmap);
        delete pixmap;
        dialogtextlabel->setText("안녕! 제대로 찾아왔군, 내가 팔이 짧아서 그런데 침대 뒤에 떨어진 내 레포트를 찾아주지 않을래?\n내가 침대를 당길게");
        dialogselectlabel[0]->setText("네 당연하죠!");
        dialogselectlabel[1]->setText("(내키지는 않지만)네...");
        nselect = 2;
    }
    else if(index==2)
    {
        //Start Game
    }
    else if(index==3)
    {
        //Succeeded in mission
        dialogtextlabel->setText("훌륭하군! 내 레포트를 찾아준 보답으로 육일콜 번호를 주도록 하지, 아 그리고 밖에 나갈거면 학생증이 필요할거야. 나는 없는데 학생증 가지고 있는 다른 인솔자 방 비밀번호를 알려줄게. " + QString::number(/*map->getPasswd()*/1234) + "잘 외워 두라고!");
        dialogselectlabel[0]->setText("고맙다고 인사한다.");
        nselect = 1;
    }
    else if(index==4)
    {
        //Fail the mission
        dialogtextlabel->setText("안타까워... 다음에 다시 찾아주길 바래");
        dialogselectlabel[0]->setText("대화 끝내기");
        nselect = 1;
    }
    else if(index==5)
    {
        pixmap = new QPixmap(":/images/room.png");
        this->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/blacksquare.png");
        dialoglabel->setPixmap(*pixmap);
        delete pixmap;
        //isInsol2Visited() == false
        dialogtextlabel->setText("인솔자 2의 방을 먼저 방문해야 할 것 같다");
        dialogselectlabel[0]->setText("나가기");
        nselect = 1;
    }
    currentindex = index;
}

//index에 대한 choice 작업 처리
void Npcdialog::insol1DialogSelect(int index, int choice)
{
    if(index==1)
    {
        if(choice==0 || choice==1)
        {
            //Start Game
            insol1Dialog(2);
        }
    }
    if(index==2)
    {
        if(choice==1)
        {
            //Succeeded in mission
            insol1Dialog(3);
        }
        else if(choice==0)
        {
            //Fail the mission
            insol1Dialog(4);
        }
    }
    if(index==3)
    {
        //room->storyfinished
        closeDialog();
    }
    if(index==4)
    {
        //room->storyfinished
        closeDialog();
    }
    if(index==5)
    {
        //room->storyfinished
        closeDialog();
    }
}

void Npcdialog::insol2DIalog(int index)
{
    if(index==1)
    {
        pixmap = new QPixmap(":/images/room.png");
        this->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/insolja2.png");
        NPCimage->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/blacksquare.png");
        dialoglabel->setPixmap(*pixmap);
        delete pixmap;
        dialogtextlabel->setText("아 누군가 찾아온다고 했는데 자고있었네... 미안해.");
        dialogselectlabel[1]->setText("괜찮다");
        dialogselectlabel[0]->setText("왜 잤느냐고 화를 낸다");
        nselect = 2;
    }
    else if(index==2)
    {
        dialogtextlabel->setText("미안해, 잘못했어..... 나가는 카드를 줄테니 용서해주라...");
        dialogselectlabel[0]->setText("카드를 받는다");
        nselect = 1;
    }
    else if(index==3)
    {
        dialogtextlabel->setText("미안... 큭큭 나가는 카드는 여기 있어.");
        dialogselectlabel[0]->setText("카드를 받는다");
        nselect = 1;
    }
    currentindex = index;
}

void Npcdialog::insol2DialogSelect(int index, int choice)
{
    if(index==1)
    {
        if(choice==1)
        {
            insol2DIalog(3);
        }
        else if(choice==0)
        {
            insol2DIalog(2);
        }
    }
    else if(index==2)
    {
        //room->storyfinished
        closeDialog();
    }
    else if(index==3)
        //room->storyfinished
        closeDialog();
}

void Npcdialog::friendDialog(int index)
{
    //int friendtype = room->getfriend()->friendtype;

    currentindex = index;
}


Npcdialog::Npcdialog(QWidget *parent, Room *_room) : QLabel(parent)
{
    //Create Labels
    NPCimage = new QLabel(this);
    dialoglabel = new QLabel(this);
    NPCname = new QLabel(this);
    dialogtextlabel = new QLabel(this);
    dialogselectlabel[0] = new QLabel(this);
    dialogselectlabel[1] = new QLabel(this);

    //Set Position of Label
    dialoglabel->move(0,0);
    NPCimage->move(50,65);
    NPCname->move(45,330);
    dialogtextlabel->move(45,370);
    dialogselectlabel[0]->move(565,413);
    dialogselectlabel[1]->move(565,455);

    //Set Inner variables
    room = _room;
    locked = room->isClosed();
    map = dynamic_cast<Map*>(parent);

    //typedef enum{INSOL1,INSOL2,INSOL3,FRIEND,EMPTY,TRAP}ROOMTYPE;
    ROOMTYPE roomtype = room->getroomtype();
    QPixmap * pixmap;
    switch(roomtype)
    {
    case INSOL1:
        pixmap = new QPixmap(":/images/room.png");
        this->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/insolja.png");
        NPCimage->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/blacksquare.png");
        dialoglabel->setPixmap(*pixmap);
        delete pixmap;
        dialogtextlabel->setText("안녕! 제대로 찾아왔군, 내가 팔이 짧아서 그런데 침대 뒤에 떨어진 내 레포트를 찾아주지 않을래?\n내가 침대를 당길게");
        dialogselectlabel[0]->setText("네 당연하죠!");
        dialogselectlabel[1]->setText("(내키지는 않지만)네...");
        break;
    }
}
