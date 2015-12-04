#include "menustrip.h"

enum stage{RC_STAGE1, RC_STAGE2, HYOJA_MARKET};

Menustrip::Menustrip(QWidget *parent, int initial_money, int initial_time, int initial_stage) : QLabel(parent)
{
    //Image
    QPixmap *pixmap;
    pixmap = new QPixmap(":/images/menustrip.png");
    setPixmap(*pixmap);
    delete pixmap;

    //Set Size
    setGeometry(0,0,740,50);

    //Set Inner Data
    money = initial_money;
    time = initial_time;
    stage = initial_stage;

    //Start Inner Timer
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(decreaseTime()));
    timer->start(1000);

    //Add Inner Label UI
    timelabel = new QLabel(this);
    moneylabel = new QLabel(this);
    timelabel->move(616, 17);
    moneylabel->move(430, 17);
    timelabel->setText(QString::number(time));
    moneylabel->setText(QString::number(money));

    //Add Inner Text UI
    stagelabel = new QLabel(this);
    pixmap = new QPixmap(":/images/rc_2nd_floor.png");
    stagelabel->setPixmap(*pixmap);
    delete pixmap;
    stagelabel->move(24,0);
}

void Menustrip::setTime(int _time)
{
    time = _time;
    refreshText();
}

void Menustrip::setMoney(int _money)
{
    money = _money;
    refreshText();
}

void Menustrip::setStage(int _stage)
{
    QPixmap * pixmap;
    stage = _stage;
    switch(stage)
    {
    case RC_STAGE1:
        pixmap = new QPixmap(":/images/rc_2nd_floor.png");
    case RC_STAGE2:
        pixmap = new QPixmap(":/images/rc_1st_floor.png");
    case HYOJA_MARKET:
        pixmap = new QPixmap(":/images/way_to_hyoja.png");
    }
    stagelabel->setPixmap(*pixmap);
    delete pixmap;
}

void Menustrip::refreshText()
{
    timelabel->setText(QString::number(time));
    moneylabel->setText(QString::number(money));
}

void Menustrip::stoptimer()
{
    timer->stop();
}

void Menustrip::resumetimer()
{
    timer->start(1000);
}

void Menustrip::decreaseTime()
{
    time--;
    refreshText();
    if(time==0)
        emit gameset();
}
