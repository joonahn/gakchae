#ifndef BAR
#define BAR

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>



class Bar: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
public:
     void draw(int xpose, int ypose, QString s, double scale);
     Bar();

public slots:
     void move();
private:
     int width;

};



#endif // BAR

