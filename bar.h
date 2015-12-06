#ifndef BAR
#define BAR

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>



class Bar: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
     Bar(int color);
private:     
     int width;
     QPixmap *red;
     QPixmap *gray;
};


#endif // BAR

