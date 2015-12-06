#ifndef GAME
#define GAME
#include <QGraphicsScene>
#include "rectangle.h"
#include <QGraphicsView>
#include "itembox.h"
#include "time.h"
#include "stdlib.h"
#include <QDebug>
#include <QWidget>
#include <QTimer>
#include "darkbed.h"
#include "background.h"
#include "QGraphicsTextItem"
#include "explain.h"
#include "fail.h"
#include "machugi.h"

class Rectangle;
class DarkBed;
namespace minigame{
class Game:public QGraphicsView{
Q_OBJECT
    public:
    Game(QWidget *parent=NULL);
    QGraphicsScene *scene;
    DarkBed * bed;
    QTimer* timer;
    QTimer* timerTurn;
    QTimer* timerHand;
    Rectangle * hand;
    BackGround * back;
    Explain * epn;
    Fail * fail;
    Machugi * machugi;
    void Reset();
    void clear();



public slots:
      void turnover();
      void turnhand();
      void timeover();
};
}

#endif // GAME

