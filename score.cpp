#include "score.h"
#include <sstream>
#include <QPixmap>
#include <QColor>
#include <QFont>
int convStringToInt(std::string s);
score::score(QWidget *parent, int time, int money):QLabel(parent)
{
    int index;
    char str[80];
    QPixmap* pixmap=new QPixmap(":/images/highscoreNew.png");//배경화면 출력
    setPixmap(*pixmap);
    delete pixmap;
    QFont* font= new QFont("Press Start");
    font->setPixelSize(25);

    Readfile("score.txt");//역대 점수 파일 읽어오기
    item* myScore= new item(time, money);
    for(index=0;index<5;index++){//내 점수보다 낮은 기록이 있는지 검색
        if(myScore->getScore()>=item_list[index]->getScore())
            break;
    }
    if(index<5){//내 점수보다 낮은 기록이 있을 때 기록 갱신
        if(index==4)
            item_list[index]=myScore;
        else
           { for(int i=4;i>index;i--)
                item_list[i]=item_list[i-1];
            item_list[index]=myScore;
        }
    }
    QColor* yellow=new QColor(239,254,0);//노란색
    QColor* red=new QColor(255,0,0);//빨간색->내 점수를 표시하는 색
    for(int j=0;j<5;j++){//label_list 초기화
        label_list[j]=new QLabel(this);
        label_list[j]->move(230,217+57*j);//label위치 설정
        palette_list[j]=label_list[j]->palette();//label 색깔설정
        if(j==index&&j<5)//내 점수일 때 빨간색으로 설정
        {
            palette_list[j].setColor(label_list[j]->backgroundRole(),*red);
            palette_list[j].setColor(label_list[j]->foregroundRole(),*red);
        }
        else//아닐때 노란색으로 설정
            {
                palette_list[j].setColor(label_list[j]->backgroundRole(),*yellow);
                palette_list[j].setColor(label_list[j]->foregroundRole(),*yellow);
            }
        label_list[j]->setPalette(palette_list[j]);
        label_list[j]->setFont(*font);//font설정

        sprintf(str,"%4d %6d %6d",item_list[j]->getTime(),item_list[j]->getMoney(),//str에 출력할내용입력
                item_list[j]->getScore());
        label_list[j]->setText(QString::fromStdString(str));
        label_list[j]->setVisible(true);
    }
    Savefile("Score.txt");//새로운 점수 파일 저장
    this->setVisible(true);
    this->setFocus();
}


void score::Readfile(std::string filename){
    std::ifstream fin;
    fin.open(filename);//1~5등 역대 점수 저장된 txt file
    if(!fin.is_open())//예외처리
        return;
    std::string s1;
    std::string s2;
    std::string s3;
    for(int i=0;i<5;i++){//txt file읽어와서 item_list에 넣어줌
        getline(fin,s1,'\t');
        getline(fin,s2,'\t');
        getline(fin,s3);
        item_list[i]=new item(convStringToInt(s1),convStringToInt(s2));
    }
}
//점수 파일 저장
void score::Savefile(std::string filename){
    ofstream fout;
    fout.open(filename);
    if(!fout.is_open())
        return;
    for(int i=0;i<5;i++){
        fout<<item_list[i]->getTime()<<'\t';
        fout<<item_list[i]->getMoney()<<'\t';
        fout<<item_list[i]->getScore()<<endl;
    }
}

void score::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
        exit(0);
    else
        event->ignore();
}




item::item(int time, int money){//class item의 constructor
    this->time=time;
    this->money=money;
    score=money+(time*10);
}
//getters&setters
void item::setScore(int score){this->score=score;}
void item::setTime(int time){this->time=time;}
void item::setMoney(int money){this->money=money;}
int item::getScore(){return score;}
int item::getTime(){return time;}
int item::getMoney(){return money;}

int convStringToInt(std::string s){//string을 int로 바꿔주는 함수
    istringstream iss(s);
        int num=0;
        iss>>num;
        return num;

}
