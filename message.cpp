#include "message.h"


Message::Message(QWidget *parent, int _type):QLabel(parent),type(_type)
{
    QPixmap * pixmap;
    QIcon * ButtonIcon;
    QFont *font;
    QPalette * palette;
    switch(type){
    case 0:
        button[0]=new QPushButton(this);
        button[1]=new QPushButton(this);


        pixmap =new QPixmap(":/images/gamestartbutton.png");
        ButtonIcon = new QIcon(*pixmap);
        button[0]->setIcon(*ButtonIcon);
        button[0]->setIconSize(pixmap->rect().size());
        button[0]->move(245,250);
        delete pixmap;
        delete ButtonIcon;
        pixmap=new QPixmap(":/images/howto_button.png");
        ButtonIcon = new QIcon(*pixmap);
        button[1]->setIcon(*ButtonIcon);
        button[1]->setIconSize(pixmap->rect().size());
        button[1]->move(245,350);
        delete pixmap;
        delete ButtonIcon;
        button[0]->setVisible(true);
        button[1]->setVisible(true);
        pixmap=new QPixmap(":/images/start_window.png");
        num=0;
        connect(button[0],SIGNAL(clicked(bool)),this,SLOT(button1clicked()));
        connect(button[1],SIGNAL(clicked(bool)),this,SLOT(button2clicked()));
        this->setGeometry(0,0,740,515);
        break;
    case 1:
        pixmap=new QPixmap(":/images/blacksquare.png");
        label=new QLabel(this);
        label->setText("잡혀버렸다... 조금 기다렸다가 다시 나가야겠다.");
        label->setGeometry(45,320,648,63);
        label->setVisible(true);
        font=new QFont("맑은 고딕",15);
        label->setFont(*font);
        palette = new QPalette(label->palette());
        palette->setColor(label->foregroundRole(), Qt::white);
        label->setPalette(*palette);
        num=1;
        this->setGeometry(0,-30, 740,515);
        break;
    case 2:
        pixmap=new QPixmap(":/images/blacksquare.png");
        label=new QLabel(this);
        label->setText("문이 잠겨있다. 아무래도 인솔자를 찾아가야겠다.");
        label->setGeometry(45,320,648,63);
        label->setVisible(true);
        font=new QFont("맑은 고딕",15);
        label->setFont(*font);
        palette = new QPalette(label->palette());
        palette->setColor(label->foregroundRole(), Qt::white);
        label->setPalette(*palette);
        num=1;
        this->setGeometry(0,-30, 740,515);
        break;
    }
    this->setPixmap(*pixmap);
    delete pixmap;
    this->setVisible(true);
    this->setFocus();
}

void Message::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Space:
        getnextscene();
        break;
    default:
        event->ignore();
    }
}

void Message::getnextscene()
{
    if(num==1)
        emit end();
    else if(num==-1){
        delete label;
        button[1]->setEnabled(true);
        button[0]->setEnabled(true);
    }
    else{
        QPixmap * pixmap;
        switch(num){
        case 4:
            pixmap=new QPixmap(":/images/intro2.png");
            break;
        case 3:
            pixmap=new QPixmap(":/images/intro3.png");
            break;
        case 2:
            pixmap=new QPixmap(":/images/intro4.png");
            break;
        }
        this->setPixmap(*pixmap);
        num--;
    }
}

void Message::button1clicked()
{
    QPixmap pixmap(":/images/intro1.png");
    this->setPixmap(pixmap);
    delete button[1];
    delete button[0];
    num=4;
    this->setFocus();
}

void Message::button2clicked()
{
    QPixmap pixmap(":/images/howtogame.png");
    label=new QLabel(this);
    label->setPixmap(pixmap);
    label->setVisible(true);
    button[0]->setEnabled(false);
    button[1]->setEnabled(false);
    num=-1;
    this->setFocus();
}

