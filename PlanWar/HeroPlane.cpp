#include "HeroPlane.h"
#include "Config.h"

HeroPlane::HeroPlane()
{
    // 加载飞机图片资源
    m_Plane.load(HERO_PATH);

    // 初始化坐标
    m_x = GAME_WIDTH * 0.5 - m_Plane.width() * 0.5;
    m_y = GAME_HEIGHT * 0.5 - m_Plane.height() - 20;

    // 初始化矩形边框 用于碰撞检测
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_x,m_y);

}

void HeroPlane::shoot()
{

}

void HeroPlane::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    m_Rect.moveTo(m_x,m_y);
}
