#ifndef MESSAGE_H
#define MESSAGE_H

#include <QLabel>
#include <QKeyEvent>
#include <QPushButton>
#include <QFont>
#include <QPalette>

class Message:public QLabel
{
    Q_OBJECT
private:
    //0 for start, 1 for caught, 2 for lock
    int type;
    int num;
    QPushButton* button[2];
    QLabel * label;

public:
    Message(QWidget* parent,int _type);
    void keyPressEvent(QKeyEvent* event);
    void getnextscene();

signals:
    void end();

public slots:
    void button1clicked();
    void button2clicked();
};

#endif // MESSAGE_H
