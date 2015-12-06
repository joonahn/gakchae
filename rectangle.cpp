#include "rectangle.h"
#include "itembox.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "fail.h"
#include <QTimer>
#include <QGraphicsView>
#include "minigame.h"
#include <QGraphicsTextItem>

#include <QDebug>
 
 extern ItemBox *itembox[7];
 extern ItemBox *getitembox[7];
 extern ItemBox *ShowitBox[7];
 extern ItemBox *ThinkingBox[7];
 extern minigame::Game * game;
 int Choogha=0;
Rectangle::Rectangle(minigame::Game* game1)
{
    setPixmap(QPixmap(":/images/image/hand.png"));
    parent_window = parent;
    game=game1;
    getitem = new QMediaPlayer();
    getitem->setMedia(QUrl("qrc:/Sound/sound/getitem.wav"));
    //connect(this,SIGNAL(Success()),parent_window,SLOT());
    //connect(NULL,SIGNAL(Fail()),this,NULL);  사실 잘모름;;;

}

void Rectangle::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
    {
        if(x()>0)
           setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right)
    {

        if(x()<620)
            setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space)
    {

        getitem->play();
        get_it();
    }
    else if(event->key()==Qt::Key_R)
    {
       FinalCheck();

    }
    else if(event->key()==Qt::Key_Q)
    {
        if(Choogha==7)
            emit Fail_signal();
    }
}
void Rectangle::get_it()
{

    if(pos().x()>itembox[0]->pos().x()-30&&pos().x()<itembox[0]->pos().x()+50&&itembox[0]->check==1)
    {


        scene()->removeItem(itembox[0]);
        scene()->removeItem(ThinkingBox[0]);
        getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[0]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
        itembox[0]->check=0;
        Choogha++;
    }


    else if(pos().x()>itembox[1]->pos().x()-30&&x()<itembox[1]->pos().x()+50&&itembox[1]->check==1)
    {
        scene()->removeItem(itembox[1]);
        scene()->removeItem(ThinkingBox[1]);
         getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[1]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
        itembox[1]->check=0;
         Choogha++;
    }

    else if((pos().x()>itembox[2]->pos().x()-30)&&(x()<itembox[2]->pos().x()+50)&&itembox[2]->check==1)
    {
        scene()->removeItem(itembox[2]);
        scene()->removeItem(ThinkingBox[2]);
        getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[2]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
        itembox[2]->check=0;
        Choogha++;

    }
    else if((pos().x()>itembox[3]->pos().x()-30)&&(x()<itembox[3]->pos().x()+50)&&itembox[3]->check==1)
    {
        scene()->removeItem(itembox[3]);
        scene()->removeItem(ThinkingBox[3]);
         getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[3]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
         itembox[3]->check=0;
        Choogha++;

    }
    else if((pos().x()>itembox[4]->pos().x()-30)&&(x()<itembox[4]->pos().x()+50)&&itembox[4]->check==1)
    {
        scene()->removeItem(itembox[4]);
        scene()->removeItem(ThinkingBox[4]);
         getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[4]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
        itembox[4]->check=0;
       Choogha++;
    }
    else if((pos().x()>itembox[5]->pos().x()-30)&&(x()<itembox[5]->pos().x()+50)&&itembox[5]->check==1)
    {
        scene()->removeItem(itembox[5]);
        scene()->removeItem(ThinkingBox[5]);
        getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[5]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
        itembox[5]->check=0;
         Choogha++;
    }
    else if((pos().x()>itembox[6]->pos().x()-30)&&(x()<itembox[6]->pos().x()+50)&&itembox[6]->check==1)
    {
        scene()->removeItem(itembox[6]);
        scene()->removeItem(ThinkingBox[6]);
         getitembox[Choogha]=new ItemBox(50*Choogha,50,itembox[6]->type);
        scene()->addItem(getitembox[Choogha]);
        getitembox[Choogha]->setScale(0.5);
         itembox[6]->check=0;
         Choogha++;
    }
    else
    {
        qDebug()<<"Wrong input!";
        qDebug()<<Choogha;

    }
    if(Choogha==7)
    {
      if((getitembox[0]->type==ShowitBox[0]->type)&&(getitembox[1]->type==ShowitBox[1]->type)&&(getitembox[2]->type==ShowitBox[2]->type)&&(getitembox[3]->type==ShowitBox[3]->type)&&(getitembox[4]->type==ShowitBox[4]->type)&&(getitembox[5]->type==ShowitBox[5]->type)&&(getitembox[6]->type==ShowitBox[6]->type))
      {
          qDebug()<<"Succeeded";
          emit Success_signal();
      }
      else
      {
         (game->fail) = new Fail();
         scene()->addItem(game->fail);
       }
    }

}

void Rectangle::FinalCheck()
{

        if(Choogha==7)
        {
            if(!((getitembox[0]->type==ShowitBox[0]->type)&&(getitembox[1]->type==ShowitBox[1]->type)&&(getitembox[2]->type==ShowitBox[2]->type)&&(getitembox[3]->type==ShowitBox[3]->type)&&(getitembox[4]->type==ShowitBox[4]->type)&&(getitembox[5]->type==ShowitBox[5]->type)&&(getitembox[6]->type==ShowitBox[6]->type)))
            {
                Choogha=0;
                game->clear();
                game->Reset();
            }
        }

}
