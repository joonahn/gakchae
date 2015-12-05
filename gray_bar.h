#ifndef GRAY_BAR
#define GRAY_BAR

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>



class gray_Bar: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
public:
     gray_Bar();

private:
     int width;
     QPixmap *gray;
};



#endif // GRAY_BAR

