#ifndef BOMB_H
#define BOMB_H

#include <QPixmap>


class Bomb
{
public:
    Bomb();

    // 更新信息 报复图片下标 播放间隔
    void updateInfo();

    // 放爆炸资源数组
    QVector<QPixmap> m_pixArr;

    // 爆炸位置
    int m_x;
    int m_y;

    // 爆炸状态
    bool m_Free;

    // 爆炸切图的时间间隔
    int m_Recorder;

    // 爆炸时加载图片的下标
    int m_index;

};

#endif // BOMB_H
