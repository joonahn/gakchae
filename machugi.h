#ifndef MACHUGI
#define MACHUGI

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

class Machugi: public QObject, public QGraphicsPixmapItem {
                  Q_OBJECT
 
public:
    Machugi();
};



#endif // MACHUGI

