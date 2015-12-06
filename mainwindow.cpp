#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new Map(this,parent);
    this->setCentralWidget(map);
    //this->setFixedSize(740,515);
    map->setFocus();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //map->keyboardInput(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}


