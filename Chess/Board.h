#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

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

    // 绘制函数
    virtual void paintEvent(QPaintEvent *event);


private:
    Ui::Board *ui;
};

#endif // BOARD_H
