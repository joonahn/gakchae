#include "minigame.h"
#include <QMediaPlayer>
#include <QGraphicsTextItem>
 
using namespace minigame;

ItemBox *ShowitBox[7];
ItemBox *itembox[7];
ItemBox *getitembox[7];
ItemBox *ThinkingBox[7];
extern int Choogha;

Game::Game(QWidget *parent)
{

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(740,515);

        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,740,515);
        setScene(scene);

        epn = new Explain();
        scene->addItem(epn);


        timer =new QTimer(this);
        timer->setInterval(10000);
        timer->start();
        connect(timer,SIGNAL(timeout()), this, SLOT(timeover()));

        hand = new Rectangle(this);
        hand->setPos(10,300);
        hand->setScale(1);
        hand->setFlag(QGraphicsItem::ItemIsFocusable);
        hand->setFocus();

        //show();
        this->setVisible(true);
}


void Game::Reset()
{

    back = new BackGround();
    scene->addItem(back);

    int num1;
    int k;
    for(int i=0;i<7;i++)
    {
        while(1) {
            num1 = rand()%7+1;
            for(k=0; k<i; k++) {
                if(num1 == ShowitBox[k]->type)
                    break;
            }
            if(k == i)
                break;

        }

        ShowitBox[i]= new ItemBox(50*i,10, num1);
        scene->addItem(ShowitBox[i]);

        ShowitBox[i]->setScale(0.5);
    }
    machugi= new Machugi();
    scene->addItem(machugi);
    int num;
    int j;
    for(int i=0;i<7;i++)
    {
        while(1) {

            num = rand()%7+1;
            for(j=0; j<i; j++) {
                if(num == itembox[j]->type)
                    break;
            }
            if(j == i)
                break;

        }

        itembox[i]= new ItemBox(100*i,400, num);
        scene->addItem(itembox[i]);

    }
    bed = new DarkBed();
    timerTurn->setInterval(3000);
    timerTurn->start();
    connect(timerTurn,SIGNAL(timeout()),this,SLOT(turnover()));
    timerHand->setInterval(4000);
    timerHand->start();
    hand = new Rectangle(this);
    hand->setPos(10,300);
    hand->setScale(1);
    hand->setFlag(QGraphicsItem::ItemIsFocusable);
    hand->setFocus();
    connect(timerHand,SIGNAL(timeout()),this,SLOT(turnhand()));

    show();
}

void Game::clear()
{

   for(int i=0;i<7;i++)
   {
    scene->removeItem(getitembox[i]);
   }
   for(int i=0;i<7;i++)
   {
       scene->removeItem(ShowitBox[i]);
   }
   scene->removeItem(hand);
   scene->removeItem(bed);
   scene->removeItem(fail);
   scene->removeItem(machugi);
}
void Game::turnover()
{
    timerTurn->stop();
    scene->addItem(bed);

    for(int i=0;i<7;i++)
    {
        scene->addItem(ThinkingBox[i]);
    }
}

void Game::turnhand()
{
    timerHand->stop();

    scene->addItem(hand);

}

void Game::timeover()
{
   timer->stop();
   scene->removeItem(epn);
   back = new BackGround();
   scene->addItem(back);
   QMediaPlayer * music= new QMediaPlayer();
   music->setMedia(QUrl("qrc:/Sound/sound/background3.mp3"));
   music->play();
   int num1;
   int k;
   for(int i=0;i<7;i++)
   {
       while(1) {
           num1 = rand()%7+1;
           for(k=0; k<i; k++) {
               if(num1 == ShowitBox[k]->type)
                   break;
           }
           if(k == i)
               break;

       }

       ShowitBox[i]= new ItemBox(50*i,10, num1);
       scene->addItem(ShowitBox[i]);
       ShowitBox[i]->setScale(0.5);
   }
   machugi= new Machugi();
  scene->addItem(machugi);
   int num;
   int j;
   for(int i=0;i<7;i++)
   {
       while(1) {
           num = rand()%7+1;
           for(j=0; j<i; j++) {
               if(num == itembox[j]->type)
                   break;
           }
           if(j == i)
               break;

       }

       itembox[i]= new ItemBox(100*i,400, num);
       scene->addItem(itembox[i]);

   }

   for(int i=0;i<7;i++)
       ThinkingBox[i]=new ItemBox(100*i,400,0);


   bed = new DarkBed();
   timerTurn = new QTimer(this);
   timerTurn->setInterval(5000);
   timerTurn->start();
   connect(timerTurn,SIGNAL(timeout()),this,SLOT(turnover()));
   timerHand = new QTimer(this);
   timerHand->setInterval(6000);
   timerHand->start();

   connect(timerHand,SIGNAL(timeout()),this,SLOT(turnhand()));


}
