#include "MainScene.h"
#include "ui_MainScene.h"

void MainScene::closeEvent(QCloseEvent *event)
{
    qDebug()<<"MainScene关闭了";
    emit closeScene();
}

MainScene::MainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
}

MainScene::~MainScene()
{
    delete ui;
}


