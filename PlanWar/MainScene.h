#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "Map.h"
#include "HeroPlane.h"
#include "Bullet.h"
#include "EnemyPlane.h"

namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

protected:
    virtual void closeEvent(QCloseEvent *event);
public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    // 初始化相关成员变量
    void initScene();

    // 定时器
    QTimer m_Timer;

    // 启动游戏 用于启动定时器对象
    void playGame();

    // 更新坐标
    void updatePosition();

    // 虚函数 重写绘制事件
    virtual void paintEvent(QPaintEvent *event);

    // 地图对象
    Map m_map;

    // 创建飞机对象
    HeroPlane m_Hero;

    // 鼠标移动事件
    virtual void mouseMoveEvent(QMouseEvent *event);

    // 敌机出场
    void enemyToScene();

    // 敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    // 敌机出场间隔
    int m_recorder;

    // 碰撞检测
    void collisionDetection();

    // 测试子弹
//    Bullet tmp_Bullet;

signals:
    // 要发送的信号 不需要实现
    void closeScene();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
