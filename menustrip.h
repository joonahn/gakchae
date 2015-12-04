#ifndef MENUSTRIP_H
#define MENUSTRIP_H

//Headers
#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QPixmap>

class Menustrip : QLabel {
    Q_OBJECT
private:
    int time;
    int money;
    int stage;
    QTimer * timer;
    QLabel * timelabel, *moneylabel;

public:
    //Constructor
    Menustrip(QWidget * parent, int initial_money, int initial_time);

    //Getters
    int getTime();
    int getMoney();
    int getStage();

    //Setters
    void setTime(int _time);
    void setMoney(int _money);
    void setStage(int _stage);

    //UI Function
    void refreshText();

public slots:
    //Slots
    void decreaseTime();
};



#endif // MENUSTRIP_H

