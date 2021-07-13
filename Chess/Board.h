#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "Stone.h"

namespace Ui {
class Board;
}

// 棋盘类
class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    // 32颗棋子
    Stone _s[32];

    // 绘制函数
    virtual void paintEvent(QPaintEvent *event);

    // 棋子半径
    int _r;

    // 返回象棋棋盘行列对应的像素坐标
    QPoint center(int row, int col);


private:
    Ui::Board *ui;

    // 绘制棋子
    void drawStone(QPainter &painter, int id);
};

#endif // BOARD_H
