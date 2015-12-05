#ifndef HEALTH
#define HEALTH

#endif // HEALTH

#include<QFont>
#include<QTimer>
#include <QGraphicsTextitem>

class Health: public QGraphicsTextItem{
Q_OBJECT
public:
    Health(QGraphicsItem * parent=0);
    int getHealth();
public slots:
    void decrease();

private:
    int health;
};
