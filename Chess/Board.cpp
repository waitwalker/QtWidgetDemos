#include "Board.h"
#include "ui_Board.h"
#include <QPainter>

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    this->_r = 20;

    for (int i = 0; i < 32; i++ ) {
        _s[i].init(i);
    }
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *event)
{
    // 定义画笔
    QPainter painter(this);

    int d = 40;

    // 画10条横线
    for (int i = 1; i <= 10 ; ++i ) {
        if (i == 1 || i == 10) {
            painter.setPen(QPen(QColor(255,255,255),4));
        } else {
            painter.setPen(QPen(QColor(255,255,255),1));
        }
        painter.drawLine(QPoint(d,i * d),QPoint(9 * d, i * d));
    }

    // 画9条竖线
    for (int i = 1; i <= 9 ; ++i) {

        if (i == 1 || i == 9) {
            painter.setPen(QPen(QColor(255,255,255),4));
            painter.drawLine(QPoint(i * d, d), QPoint(i * d, 10 * d));
        } else {
            painter.setPen(QPen(QColor(255,255,255),1));
            painter.drawLine(QPoint(i * d, d), QPoint(i * d, 5 * d));
            painter.drawLine(QPoint(i * d, 6 * d), QPoint(i * d, 10 * d));
        }
    }

    // 画九宫格
    painter.setPen(QPen(QColor(255,255,255),1));
    painter.drawLine(QPoint(4 * d, d), QPoint(6 * d, 3 * d));
    painter.drawLine(QPoint(6 * d, d), QPoint(4 * d, 3 * d));

    painter.drawLine(QPoint(4 * d, 8 * d), QPoint(6 * d, 10 * d));
    painter.drawLine(QPoint(6 * d, 8 * d), QPoint(4 * d, 10 * d));

    painter.drawText(QPoint(2.5 * d, 5.5 * d),"楚河");
    painter.drawText(QPoint(7 * d, 5.5 * d),"汉界");

    // 绘制32颗棋子
    for (int i = 0; i < 32 ;++i ) {
        this->drawStone(painter, i);
    }


}

QPoint Board::center(int row, int col)
{
    QPoint ret;
    //ret.setX(col * _r * 2);
    //ret.setY(row * _r * 2);
    ret.rx() = (col + 1) * _r * 2;
    ret.ry() = (row + 1) * _r * 2;
    return ret;
}

QPoint Board::center(int id)
{
    return center(_s[id]._row,_s[id]._col);
}

void Board::drawStone(QPainter &painter, int id)
{
    qDebug()<<"当前行:"<<_s[id]._row<<"当前列:"<<_s[id]._col;
    painter.setBrush(QBrush(QColor(155,155,0)));
    if (_s[id]._red) {
        painter.setPen(Qt::red);
    } else {
        painter.setPen(Qt::black);
    }

    // 根据棋子的行和列坐标 转换成棋盘的像素坐标, 说白了就在这个id位置画一个圆圈
    painter.drawEllipse(center(id), _r, _r);

    QPoint c = center(id);

    QRect rect = QRect(c.x() - _r, c.y() - _r , _r * 2, _r *2);

    // 画文字
    painter.drawText(rect, _s[id].getText(),QTextOption(Qt::AlignCenter));
}

