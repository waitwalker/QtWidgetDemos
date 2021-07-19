#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "MainScene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton("打开", this);
    button->setGeometry(150,100,100,60);
    MainScene *main = new MainScene;
    connect(button,&QPushButton::clicked,[=](){
        qDebug()<<"点击了按钮";
        main->show();
        this->hide();
    });

    connect(main,&MainScene::closeScene,[=](){
        this->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

