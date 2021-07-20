#include "EnemyPlane.h"

EnemyPlane::EnemyPlane()
{
    // 敌机资源加载
    m_enemy.load(ENEMY_PATH);

    // 敌机位置
    m_x = 0;
    m_y = 0;

    // 敌机状态
    m_Free = true;

    // 敌机速度
    m_Speed = ENEMY_SPEED;

    // 敌机矩形边框 用于碰撞检测
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_x,m_y);

}

void EnemyPlane::updatePosition()
{
    // 空闲状态 不计算坐标
    if (m_Free) {
        return;
    }

    m_y += m_Speed;
    m_Rect.moveTo(m_x,m_y);
    if (m_y >= GAME_HEIGHT) {
        m_Free = true;
    }
}
