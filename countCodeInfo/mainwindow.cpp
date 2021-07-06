#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralwidget->setStyleSheet("background:rgb(200,100,100)");
    ui->countWidget->setGeometry(0,0,100,100);
    ui->countWidget->setFixedSize(this->width(),this->height());
    countWidget = ui->countWidget;
    //countWidget->setStyleSheet("background:rgb(100,200,0)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

