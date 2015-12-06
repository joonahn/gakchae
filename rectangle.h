#ifndef RECTANGLE
#define RECTANGLE

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "itembox.h"
#include "minigame.h"

namespace minigame{
class Game;
}


class Rectangle : public QObject, public QGraphicsPixmapItem {

public:
    Rectangle(minigame::Game *);
    void keyPressEvent(QKeyEvent *event);
    void get_it();
    void FinalCheck();
signals:
     // void Success();
     // void Fail();

private:
    minigame::Game *game;
    QMediaPlayer * getitem;
};



#endif // RECTANGLE

