#include "MainScene.h"
#include "ui_MainScene.h"
#include "Config.h"
#include <QPainter>
#include <QIcon>
#include <QMouseEvent>

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

    // 发射子弹
    m_Hero.shoot();

    // 计算子弹坐标
    for (int i =0; i < BULLET_NUM ;i++ ) {
        // 如果子弹状态为非空闲, 计算发射位置
        if (m_Hero.m_bullets[i].m_Free == false) {
            m_Hero.m_bullets[i].updatePosition();
        }
    }

    // 测试坐标;
//    tmp_Bullet.m_Free = false;
//    tmp_Bullet.updatePosition();
}

void MainScene::paintEvent(QPaintEvent *event)
{
    // 利用画家(画笔)
    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY, m_map.m_map2);

    // 绘制飞机
    painter.drawPixmap(m_Hero.m_x,m_Hero.m_y,m_Hero.m_Plane);

    // 绘制子弹
    for (int i = 0; i < BULLET_NUM; i++) {
        // 如果子弹状态非空闲, 绘制图片
        if (m_Hero.m_bullets[i].m_Free == false) {
            painter.drawPixmap(m_Hero.m_bullets[i].m_x,m_Hero.m_bullets[i].m_y,m_Hero.m_bullets[i].m_Bullet);
        }
    }

    // 测试子弹
//    painter.drawPixmap(tmp_Bullet.m_x,tmp_Bullet.m_y,tmp_Bullet.m_Bullet);
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    // 获取鼠标的真实位置与偏移位置
    int x = event->pos().x() - m_Hero.m_Rect.width() * 0.5;
    int y = event->pos().y() - m_Hero.m_Rect.height() * 0.5;

    // 边界检测
    if (x <= 0) {
        x = 0;
    }

    if (x >= GAME_WIDTH - m_Hero.m_Rect.width()) {
        x = GAME_WIDTH - m_Hero.m_Rect.width();
    }

    if (y <= 0) {
        y = 0;
    }

    if (y >= GAME_HEIGHT - m_Hero.m_Rect.height()) {
        y = GAME_HEIGHT - m_Hero.m_Rect.height();
    }


    m_Hero.setPosition(x,y);
}


