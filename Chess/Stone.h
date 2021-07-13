#ifndef STONE_H
#define STONE_H


class Stone
{
public:
    Stone();
    ~Stone();

    enum TYPE {
        JIANG,
        CHE,
        PAO,
        MA,
        BING,
        SHI,
        XIANG
    };

    // 在棋盘上的行
    int _row;

    // 在棋盘上的列
    int _col;

    // 棋子id
    int _id;

    // 有没有挂掉
    bool _dead;

    // 是否红方 黑方
    bool _red;

    // 类型
    TYPE _type;
};

#endif // STONE_H
