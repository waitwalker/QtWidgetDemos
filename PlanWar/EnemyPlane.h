#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QRect>
#include <QPixmap>
#include "Config.h"



class EnemyPlane
{
public:
    EnemyPlane();

    // 更新坐标
    void updatePosition();

    // 敌机资源对象
    QPixmap m_enemy;

    // 位置
    int m_x;
    int m_y;

    // 敌机的矩形边 框 用于碰撞检测
    QRect m_Rect;

    // 状态
    bool m_Free;

    // 速度
    int m_Speed;
};

#endif // ENEMYPLANE_H
