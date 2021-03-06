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

    // 鼠标释放事件 棋子选中
    virtual void mouseReleaseEvent(QMouseEvent *event);

    // 判断棋子是否可以移动
    bool canMove(int moveId, int row, int col, int killId);
    bool canMove1(int moveId, int row, int col, int killId);
    bool canMove2(int moveId, int row, int col, int killId);
    bool canMove3(int moveId, int row, int col, int killId);
    bool canMove4(int moveId, int row, int col, int killId);
    bool canMove5(int moveId, int row, int col, int killId);
    bool canMove6(int moveId, int row, int col, int killId);
    bool canMove7(int moveId, int row, int col, int killId);

    // 棋子半径
    int _r;

    // 选中的棋子id
    int _selectedId;

    // 返回象棋棋盘行列对应的像素坐标
    QPoint center(int row, int col);

    // 重载
    QPoint center(int id);

    // 根据点击的位置获取对应的行和列
    bool getRowCol(QPoint pt, int &row, int &col);



private:
    Ui::Board *ui;

    // 绘制棋子
    void drawStone(QPainter &painter, int id);
};

#endif // BOARD_H
