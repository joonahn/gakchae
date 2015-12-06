#ifndef MONEY
#define MONEY

#include <QGraphicsTextitem>
#include<QFont>
#include<QTimer>
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
};


#endif // MONEY

