#ifndef FAIL
#define FAIL
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
 
class Fail: public QObject, public QGraphicsPixmapItem {
                  Q_OBJECT

public:
    Fail();
};



#endif // FAIL

