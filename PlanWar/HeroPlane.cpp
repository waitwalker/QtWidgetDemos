#include "HeroPlane.h"

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

    // 初始化间隔记录变量
    m_recorder = 0;
}

void HeroPlane::shoot()
{
    // 累加时间间隔记录的变量
    m_recorder++;
    // 如果记录的数字 未达到发射间隔 直接return
    if (m_recorder < BULLET_INTERVAL) {
        return;
    }

    m_recorder = 0;

    // 发射子弹
    for(int i = 0; i < BULLET_NUM;i++) {
        // 如果子弹是空闲状态 发射出去
        if (m_bullets[i].m_Free) {
            m_bullets[i].m_Free = false;
            m_bullets[i].m_x = m_x + m_Rect.width() * 0.5 - 10;
            m_bullets[i].m_y = m_y - 25;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    m_Rect.moveTo(m_x,m_y);
}
