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
Q_OBJECT
public:
    Rectangle(minigame::Game *, QWidget *parent);
    void keyPressEvent(QKeyEvent *event);
    void get_it();
    void FinalCheck();
signals:
     void Success_signal();
     void Fail_signal();

private:
    minigame::Game *game;
    QMediaPlayer * getitem;
    QWidget * parent_window;
};



#endif // RECTANGLE

