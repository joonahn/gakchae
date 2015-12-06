#ifndef MONEY
#define MONEY

#include <QGraphicsTextitem>
#include<QFont>
#include<QTimer>
#include"gamescene.h"
#include"QMediaPlayer"

class Money: public QGraphicsTextItem{
Q_OBJECT
public:
    Money(QGraphicsItem * parent=0);
    int getmoney();
    void starttimer();
    void stoptimer();
public slots:
    void increase();    
private:
    int money;
    QTimer *timer;
    Gamescene *gameover1;
    QMediaPlayer * gameover1_bgm;
};


#endif // MONEY

