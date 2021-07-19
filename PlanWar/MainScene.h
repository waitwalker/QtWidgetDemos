#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "Map.h"

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

    virtual void paintEvent(QPaintEvent *event);

    // 地图对象
    Map m_map;

signals:
    // 要发送的信号 不需要实现
    void closeScene();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
