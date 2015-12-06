#ifndef SCORE_H
#define SCORE_H
#include <QLabel>
#include <fstream>
#include <string>
#include <QPalette>
#include <QKeyEvent>
using namespace std;
class item;
class score: public QLabel{
    QLabel* name1;
    QLabel* label_list[5];//출력할 정보를 담는 QLabel
    QPalette palette_list[5];
    item* item_list[5];//출력할 정보
public:
    score(QWidget * parent,int money, int time);//생성자
    void Readfile(std::string filename);//파일을 읽어 item_list에 정보를 저장
    void Savefile(std::string filename);//플레이어의 점수를 update 한 정보를 다시 파일에 저장
    void keyPressEvent(QKeyEvent* event);
};

class item{//1명의 점수, 시간, 돈의 정보를 담는 class
    int score;//=time+money*10
    int time;
    int money;
public:
    item(int time, int money);//생성자
    //아래는 getter, setter
    void setScore(int score);
    void setTime(int time);
    void setMoney(int money);
    int getScore();
    int getTime();
    int getMoney();
};
#endif // SCORE_H

