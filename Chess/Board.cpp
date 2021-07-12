#include "Board.h"
#include "ui_Board.h"
#include <QPainter>

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *event)
{
    // 定义画笔
    QPainter painter(this);

    // 棋子直径
    int d = 50;

    // 画10条横线
    for (int i = 1; i < 11 ; i++ ) {
        painter.drawLine(QPoint(d,i * d),QPoint(9 * d, i * d));
    }

    // 画9条竖线
    for (int i = 1; i < 10 ; i++) {
        if (i == 1 || i == 9) {
            painter.drawLine(QPoint(i * d, d), QPoint(i * d, 10 * d));
        } else {
            painter.drawLine(QPoint(i * d, d), QPoint(i * d, 5 * d));
            painter.drawLine(QPoint(i * d, 6 * d), QPoint(i * d, 10 * d));
        }
    }

    // 画九宫格
    painter.drawLine(QPoint(4 * d, d), QPoint(6 * d, 3 * d));
    painter.drawLine(QPoint(6 * d, d), QPoint(4 * d, 3 * d));

    painter.drawLine(QPoint(4 * d, 8 * d), QPoint(6 * d, 10 * d));
    painter.drawLine(QPoint(6 * d, 8 * d), QPoint(4 * d, 10 * d));


}
