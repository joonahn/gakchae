#include "menustrip.h"



Menustrip::Menustrip(QWidget *parent, int initial_money, int initial_time) : QLabel(parent)
{
    QPixmap *pixmap;
    pixmap = new QPixmap(":/images/menustrip.png");
    setPixmap(*pixmap);
    delete pixmap;
    setGeometry(0,0,740,50);
    money = initial_money;
    time = initial_time;
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(decreaseTime()));
    timer->start(1000);
    timelabel = new QLabel(this);
    timelabel->move(616, 17);
    timelabel->setText(QString::number(time));
    moneylabel = new QLabel(this);
    moneylabel->setText(QString::number(money));
    moneylabel->move(430, 17);
}

void Menustrip::refreshText()
{
    timelabel->setText(QString::number(time));
    moneylabel->setText(QString::number(money));
}

void Menustrip::decreaseTime()
{
    time--;
    refreshText();
}
