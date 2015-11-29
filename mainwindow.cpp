#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new Map(this);
    this->setCentralWidget(map);
}

MainWindow::~MainWindow()
{
    delete ui;
}
