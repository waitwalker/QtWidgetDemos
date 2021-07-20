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
    playGame();

    // 敌机出场记录变量 初始化
    m_recorder = 0;

    // 随机数种子
    srand((unsigned int)time(NULL));
}

// 玩游戏
void MainScene::playGame()
{
    // 启动定时器
    m_Timer.start();

    // 监听定时器信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        // 敌机出场
        enemyToScene();

        // 更新游戏中所有元素的坐标
        updatePosition();

        // 游戏中的元素 绘制到屏幕中
        update();

        // 碰撞检测
        collisionDetection();
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

    // 敌机坐标计算
    for (int i = 0; i < ENEMY_NUM ;i++ ) {
        // 非空闲敌机 更新坐标
        if (m_enemys[i].m_Free == false) {
            m_enemys[i].updatePosition();
        }
    }

    // 计算爆炸播放的图片
    for (int i = 0; i < BOMB_NUM ; i++) {
        if (m_bombs[i].m_Free == false) {
            m_bombs[i].updateInfo();
        }
    }

    // 测试坐标;
//    tmp_Bullet.m_Free = false;
//    tmp_Bullet.updatePosition();
}

void MainScene::paintEvent(QPaintEvent *)
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

    // 绘制敌机
    for (int i = 0; i < ENEMY_NUM; i++) {
        // 如果敌机状态为非空闲 绘制图片
        if (m_enemys[i].m_Free == false) {
            painter.drawPixmap(m_enemys[i].m_x,m_enemys[i].m_y,m_enemys[i].m_enemy);
        }
    }

    // 绘制爆炸图片
    for (int i = 0; i < BOMB_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            painter.drawPixmap(m_bombs[i].m_x,m_bombs[i].m_y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
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

void MainScene::enemyToScene()
{
    // 累加出场间隔
    m_recorder++;
    if (m_recorder < ENEMY_INTERVAL) {
        return;
    }

    m_recorder = 0;
    for (int i = 0; i < ENEMY_NUM ; i++ ) {
        if (m_enemys[i].m_Free) {
            // 敌机空闲状态改为false
            m_enemys[i].m_Free = false;

            // 设置坐标
            m_enemys[i].m_x = rand() % (GAME_WIDTH - m_enemys[i].m_enemy.width());
            m_enemys[i].m_y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    // 遍历所有非空闲的敌机
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free) {
            // 空闲飞机 跳转下一次循环
            continue;
        }

        // 遍历所有 非空闲的子弹
        for (int j = 0; j < BULLET_NUM ;j++ ) {
            if (m_Hero.m_bullets[j].m_Free) {
                // 空闲子弹 跳转下一次循环
                continue;
            }

            // 如果子弹矩形框和敌机矩形框相交,发生碰撞,同时变为空闲状态即可
            if (m_enemys[i].m_Rect.intersects(m_Hero.m_bullets[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_Hero.m_bullets[j].m_Free = true;

                // 调用爆炸特效
                for (int k = 0; k < BOMB_NUM ;k++ ) {
                    if (m_bombs[k].m_Free) {
                        // 爆炸状态设置为非空闲
                        m_bombs[k].m_Free = false;

                        // 更新坐标
                        m_bombs[k].m_x = m_enemys[i].m_x;
                        m_bombs[k].m_y = m_enemys[i].m_y;
                        break;
                    }
                }
            }
        }
    }
}


