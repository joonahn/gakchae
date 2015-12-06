#ifndef SUMMONER
#define SUMMONER
#include"taxi.h"
#include"building.h"
#include"QMediaPlayer"
#include"building2floor.h"

class Summoner : public QObject, public  QGraphicsRectItem{
private:
    Q_OBJECT
    int xposi;
    int yposi;
    int count;
    int numstart;
    int nomalnum;
    int specialnum;
    int floor2num;
    QTimer *timerend;
    QGraphicsScene * scene;
    QGraphicsPixmapItem *redbar;
    QGraphicsPixmapItem *greybar;


public:
    Summoner(QGraphicsScene * _scene);
    void setxposi(int x);
    void decrease_count();
    int getcount();
    void decrease_special();

public slots:
    void spawn();
};










#endif // SUMMONER

