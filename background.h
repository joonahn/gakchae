#ifndef BACKGROUND
#define BACKGROUND
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

class BackGround: public QObject, public QGraphicsPixmapItem {
                  Q_OBJECT

public:
    BackGround();
};




#endif // BACKGROUND

 