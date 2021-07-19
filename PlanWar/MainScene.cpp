#include "MainScene.h"
#include "ui_MainScene.h"
#include "Config.h"
#include <QPainter>
#include <QIcon>

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
    playGame();

      // 设置背景
//    QPalette palette;
//    QPixmap pixmap(MAP_PATH);
//    palette.setBrush(QPalette::Window, QBrush(pixmap));
//    this->setPalette(palette);
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    this->setWindowTitle(GAME_TITLE);
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowIcon(QIcon(":/images/app.ico"));

    m_Timer.setInterval(GAME_RATE );

}

// 玩游戏
void MainScene::playGame()
{
    // 启动定时器
    m_Timer.start();

    // 监听定时器信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        // 更新游戏中所有元素的坐标
        updatePosition();

        // 游戏中的元素 绘制到屏幕中
        update();
    });
}

void MainScene::updatePosition()
{
    // 更新地图坐标
    m_map.mapPosition();
}

void MainScene::paintEvent(QPaintEvent *event)
{
    // 利用画家(画笔)
    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY, m_map.m_map2);
}


