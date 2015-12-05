#include "npcdialog.h"
#include "map.h"

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
    QPixmap * pixmap;
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
    QPixmap * pixmap;
    if(index==1)
    {
        pixmap = new QPixmap(":/images/darkroom.png");
        this->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/blacksquare.png");
        dialoglabel->setPixmap(*pixmap);
        delete pixmap;
        NPCname->setText("친구 1");
        dialogtextlabel->setText("친구가 자고 있다");
        dialogselectlabel[0]->setText("나가기");
        nselect = 1;
    }
    else if(index==2)
    {
        //무슨일이야 출력
        int friendtype = room->getfriend()->friendtype;
        pixmap = new QPixmap(":/images/room.png");
        this->setPixmap(*pixmap);
        delete pixmap;
        pixmap = new QPixmap(":/images/blacksquare.png");
        dialoglabel->setPixmap(*pixmap);
        delete pixmap;
        if(friendtype==1)//술먹으러 간다
        {
            pixmap = new QPixmap(":/images/bluefriend.png");
            NPCimage->setPixmap(*pixmap);
            delete pixmap;
            NPCname->setText("친구 2");
        }
        else if(friendtype==2)
        {
            pixmap = new QPixmap(":/images/purplefriend.png");
            NPCimage->setPixmap(*pixmap);
            delete pixmap;
            NPCname->setText("친구 3");
        }

        dialogtextlabel->setText("오 안녕 친구야! 무슨일이니?");
        dialogselectlabel[0]->setText("술마시러 나가자고 꼬신다");
        nselect = 1;
    }
    else if(index==3)
    {
        dialogtextlabel->setText("그래! 가자. 너 갈때 불러!");
        dialogselectlabel[0]->setText("대화 끝내기");
        nselect = 1;
    }
    else if(index==4)
    {
        dialogtextlabel->setText("나 그냥 잘래...");
        dialogselectlabel[0]->setText("대화 끝내기");
        nselect = 1;
    }
    currentindex = index;
}

void Npcdialog::friendDialogSelect(int index, int choice)
{
    if(index == 1)
        closeDialog();
    else if(index == 2)
    {
        int friendtype = room->getfriend()->friendtype;
        if(friendtype==1)
            friendDialog(3);
        else if(friendtype==2)
            friendDialog(4);
    }
    else if(index==3)
    {
        map->getMenu()->setMoney(
                    map->getMenu()->getMoney() + room->getfriend()->money);
        room->deletefriend();
        closeDialog();
    }
    else if(index==4)
    {
        closeDialog();
    }
}

void Npcdialog::emptyDialog()
{
    QPixmap * pixmap;
    pixmap = new QPixmap(":/images/darkroom.png");
    this->setPixmap(*pixmap);
    delete pixmap;
    pixmap = new QPixmap(":/images/blacksquare.png");
    dialoglabel->setPixmap(*pixmap);
    delete pixmap;
    NPCname->setText("빈 방");
    dialogtextlabel->setText("그냥 빈 방이다.");
    dialogselectlabel[0]->setText("나가기");
    nselect = 1;
}

void Npcdialog::emptyDialogSelect()
{
    closeDialog();
}

void Npcdialog::trapDialog()
{
    QPixmap * pixmap;
    pixmap = new QPixmap(":/images/room.png");
    this->setPixmap(*pixmap);
    delete pixmap;
    pixmap = new QPixmap(":/images/redfriend.png");
    NPCimage->setPixmap(*pixmap);
    delete pixmap;
    pixmap = new QPixmap(":/images/blacksquare.png");
    dialoglabel->setPixmap(*pixmap);
    delete pixmap;
    NPCname->setText("새준위 및 인솔자");
    dialogtextlabel->setText("너 이자식 이시간에 왜 돌아다니는거야!");
    dialogselectlabel[0]->setText("방으로 강제송환");
    nselect = 1;
}

void Npcdialog::trapDialogSelect()
{
    map->reset();
    closeDialog();
}

void Npcdialog::passwdDialog()
{
    QPixmap * pixmap;
    pixmap = new QPixmap(":/images/doorlock_back.png");
    this->setPixmap(*pixmap);
    delete pixmap;
    NPCname->setVisible(false);
    NPCimage->setVisible(false);
    dialoglabel->setVisible(false);
    dialogtextlabel->setVisible(false);
    for(int i = 0;i<2;i++)
        dialogselectlabel[i]->setVisible(false);
}

void Npcdialog::passwdDialogSelect(int choice)
{
    /*Non-Exceptional case, choice : number, backspace, enter
    **choice : backspace : -1, enter : -2
    **ESC : -3  */
    if(choice >=0 && choice <=9)
    {
        //Key Input
        if(inputpw.length()>=4)
        {
            return;
        }
        else
        {
            inputpw.append((const char)('0' + choice));
        }
    }
    else if (choice == -1)
    {
        //Backspace
        if(inputpw.length()>0)
            inputpw.remove(inputpw.length()-1,1);
    }
    else if(choice == -2)
    {
        //Enter key : OK
        if(inputpw.length()==4)
        {
            if(room->open() == inputpw.toInt())
            {
                //change UI
                for(int i = 0;i<4;i++)
                    inputpwlabel[i]->setVisible(false);
                NPCname->setVisible(true);
                NPCimage->setVisible(true);
                dialoglabel->setVisible(true);
                dialogtextlabel->setVisible(true);
                for(int i = 0;i<2;i++)
                    dialogselectlabel[i]->setVisible(true);

                //Call proper UI Function
                switch(room->getroomtype())
                {
                case INSOL1:
                    insol1Dialog(1);
                    break;
                case INSOL2:
                    insol2DIalog(1);
                    break;
                case INSOL3:
                    trapDialog();
                    break;
                case FRIEND:
                {
                    if((room->getfriend()->friendtype)==0)
                        friendDialog(1);
                    else
                        friendDialog(2);
                    break;
                }
                case TRAP:
                    trapDialog();
                    break;
                case EMPTY:
                    emptyDialog();
                    break;
                }
            }
        }
    }
    else if (choice == -3)
    {
        closeDialog();
    }
}

void Npcdialog::closeDialog()
{
    emit resumeGame();
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
    inputpwlabel[0] = new QLabel(this);
    inputpwlabel[1] = new QLabel(this);
    inputpwlabel[2] = new QLabel(this);
    inputpwlabel[3] = new QLabel(this);

    //Set Position of Label
    setGeometry(0,0,740,515);
    dialoglabel->setGeometry(0,0, 740,515);
    NPCimage->move(50,65);
    NPCname->move(45,330);
    dialogtextlabel->move(45,370);
    dialogselectlabel[0]->move(565,413);
    dialogselectlabel[1]->move(565,455);
    inputpwlabel[0]->move(248,448);
    inputpwlabel[1]->move(320,448);
    inputpwlabel[2]->move(390,448);
    inputpwlabel[3]->move(460,448);

    //Make it visible
    this->setVisible(true);
    NPCname->setVisible(true);
    NPCimage->setVisible(true);
    dialoglabel->setVisible(true);
    dialogtextlabel->setVisible(true);
    for(int i = 0;i<2;i++)
        dialogselectlabel[i]->setVisible(true);

    //Set Inner variables
    unlocked = room->isClosed();
    room = _room;
    map = dynamic_cast<Map*>(parent);

    //Connect
    connect(this, SIGNAL(resumeGame()), map, SLOT(resume()));

    //typedef enum{INSOL1,INSOL2,INSOL3,FRIEND,EMPTY,TRAP}ROOMTYPE;
    if(room->isClosed())
    {
        passwdDialog();
    }
    else
    {
        ROOMTYPE roomtype = room->getroomtype();
        switch(roomtype)
        {
        case INSOL1:
            insol1Dialog(1);
            break;
        case INSOL2:
            insol2DIalog(1);
            break;
        case INSOL3:
            trapDialog();
            break;
        case FRIEND:
        {
            if((room->getfriend()->friendtype)==0)
                friendDialog(1);
            else
                friendDialog(2);
            break;
        }
        case TRAP:
            trapDialog();
            break;
        case EMPTY:
            emptyDialog();
            break;
        }
    }
}

void Npcdialog::keyboardInput(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        closeDialog();
        break;
    default:
        event->ignore();
        break;
    }
}
