#include "Map.h"
#include "Config.h"
Map::Map()
{
    // 初始化加载地图图片对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    // 设置两张图片的坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    // 设置滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;

}

void Map::mapPosition()
{
    // 处理第一张图片的滚动
    m_map1_posY += m_scroll_speed;
    if (m_map1_posY >=0) {
        m_map1_posY = -GAME_HEIGHT;
    }

    m_map2_posY += m_scroll_speed;
    if (m_map2_posY >= GAME_HEIGHT) {
        m_map2_posY = 0;
    }
}
