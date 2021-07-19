#include "MainScene.h"
#include "ui_MainScene.h"
#include "Config.h"

void MainScene::closeEvent(QCloseEvent *event)
{
    qDebug()<<"MainScene关闭了";
    // 发送事件
    emit closeScene();
}

MainScene::MainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    this->setWindowTitle(GAME_TITLE);
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
}


