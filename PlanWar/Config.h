#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH 512 //宽度
#define GAME_HEIGHT 768 //高度
#define GAME_TITLE "飞机大战 v1.0" //标题

#define GAME_ICON ":/images/app.ico" // 图标

#define MAP_PATH ":/images/img_bg_level_1.jpg" //地图图片路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度

#define GAME_RATE 10 //帧率 单位毫秒

// 飞机相关配置
#define HERO_PATH ":/images/hero2.png"


#define BULLET_PATH ":/images/bullet_11.png" // 子弹图片路径
#define BULLET_SPEED 5 // 子弹移动速度

#define BULLET_NUM 30 // 弹夹中子弹总数
#define BULLET_INTERVAL 20 // 发射子弹时间间隔

#define ENEMY_PATH ":/images/img-plane_5.png" // 低级资源图片
#define ENEMY_SPEED 5 // 敌机移动速度
#define ENEMY_NUM 20 // 敌机总数量
#define ENEMY_INTERVAL 30// 敌机出场时间间隔

#define BOMB_PATH ":/images/bomb-%1.png" // 爆炸资源图片 %1作为格式化索引
#define BOMB_NUM 20 //炸弹数量
#define BOMB_MAX 7 // 炸弹图片最大索引
#define BOMB_INTERVAL 20 // 爆炸切图时间间隔


#define SOUND_BACKGROUND ":/images/bg.wav"
#define SOUND_BOMB ":/images/bomb.wav"

#endif // CONFIG_H
