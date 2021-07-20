#ifndef HEROPLANE_H
#define HEROPLANE_H

#include <QPixmap>



class HeroPlane
{
public:
    HeroPlane();

    // 发射子弹
    void shoot();

    // 设置飞机位置
    void setPosition(int x, int y);

    // 飞机资源对象
    QPixmap m_Plane;

    // 飞机坐标
    int m_x;
    int m_y;

    // 飞机的矩形边框
    QRect m_Rect;
};

#endif // HEROPLANE_H
