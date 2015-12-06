#ifndef COLOR_BAR
#define COLOR_BAR

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>



class color_Bar: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
public:
     color_Bar();

private:
     int width;
     QPixmap *red;
};


#endif // COLOR_BAR

