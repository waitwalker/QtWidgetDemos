#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "colorsuckwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton("弹出",this);
    connect(button,&QPushButton::clicked,[=](){
        qDebug()<<"弹出";
        ColorSuckWidget::sharedInstance()->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

