#include "Board.h"
#include "ui_Board.h"
#include <QPainter>
#include <QMouseEvent>

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    this->_r = 20;
    _selectedId = -1;

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

void Board::mouseReleaseEvent(QMouseEvent *event)
{
    // 鼠标点中 释放
    QPoint pt = event->pos();
    qDebug()<<pt.x();
    qDebug()<<pt.y();
    // 将pt转换成象棋的行列值
    int row, col;
    bool bRet = getRowCol(pt,row,col);
    // 点到棋盘外
    if (bRet == false) {
        return;
    }

    // 判断这个行列值上面有无棋子
    // 获取当前点击棋子的id 如果当前行列上有棋子,就会被吃掉,相当于在_s数组里面替换成当前点击的棋子
    int i;
    int clickedId = -1;
    for (i = 0; i < 32 ; i++ ) {
        // 当前棋子被选中
        if (_s[i]._row == row && _s[i]._col == col && _s[i]._dead == false) {
            break;
        }
    }

    if (i < 32) {
        clickedId = i;
        update();
    }

    // 没有选中棋子之前
    if (_selectedId == -1) {
        if(clickedId != -1) {
            _selectedId = clickedId;
            update();
        }
    } else {
        // 选中棋子之后 可以移动
        // 先判断是否可以走
        if (canMove(_selectedId, row, col, clickedId)) {
            _s[_selectedId]._row = row;
            _s[_selectedId]._col = col;
            if (clickedId != -1) {
                _s[clickedId]._dead = true;
            }
            _selectedId = -1;
            update();
        }
    }
}

bool Board::canMove(int moveId, int row, int col, int killId)
{
    // 如果选中的棋子颜色和即将被杀掉棋子颜色相同,不能被移动
    if (_s[moveId]._red == _s[killId]._red) {
        // 换选择
        _selectedId = killId;
        update();
        return false;
    }
    switch (_s[moveId]._type) {
    case Stone::JIANG:
        return canMove1(moveId,row,col,killId);
        break;
    case Stone::SHI:
        canMove2(moveId,row,col,killId);
        break;
    case Stone::XIANG:
        canMove3(moveId,row,col,killId);
        break;
    case Stone::CHE:
        canMove4(moveId,row,col,killId);
        break;
    case Stone::MA:
        canMove5(moveId,row,col,killId);
        break;
    case Stone::PAO:
        canMove6(moveId,row,col,killId);
        break;
    case Stone::BING:
        canMove7(moveId,row,col,killId);
        break;
    }
    return true;
}

bool Board::canMove1(int moveId, int row, int col, int killId)
{
    // 将的规则
    // 1.在九宫格内移动
    // 2.每次最多移动一个
    if (_s[moveId]._red) {
        if (row > 2) {
            return false;
        }
    } else {
        if (row < 7) {
            return false;
        }
    }

    if (col < 3 || col > 5) {
        return false;
    }

    // 移动的距离
    int dRow = _s[moveId]._row - row;
    int dCol = _s[moveId]._col - col;
    int d = abs(dRow) * 10 + abs(dCol);
    if (d == 1 || d == 10) {
        return true;
    }
    return false;
}

bool Board::canMove2(int moveId, int row, int col, int killId)
{
    return true;
}

bool Board::canMove3(int moveId, int row, int col, int killId)
{
    return true;
}

bool Board::canMove4(int moveId, int row, int col, int killId)
{
    return true;
}

bool Board::canMove5(int moveId, int row, int col, int killId)
{
    return true;
}

bool Board::canMove6(int moveId, int row, int col, int killId)
{
    return true;
}

bool Board::canMove7(int moveId, int row, int col, int killId)
{
    return true;
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

// 效率不高 应该改进
bool Board::getRowCol(QPoint pt, int &row, int &col)
{
    for (row = 0; row <= 9 ; row++ ) {
        for (col = 0; col <= 8; col++ ) {
            // 计算行和列对应的坐标
            QPoint c = center(row, col);

            int dx = c.x() - pt.x();
            int dy = c.y() - pt.y();

            // 计算点击的区域
            int dist = dx * dx + dy * dy;
            if (dist < _r * _r) {
                return true;
            }

        }
    }
    return false;
}

void Board::drawStone(QPainter &painter, int id)
{
    if (_s[id]._dead) {
        return;
    }

    qDebug()<<"当前行:"<<_s[id]._row<<"当前列:"<<_s[id]._col;
    // 被选中的棋子 背景颜色要高亮
    if (id == _selectedId) {
        painter.setBrush(QBrush(Qt::gray));
    } else {
        painter.setBrush(QBrush(QColor(155,155,0)));
    }
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
    painter.setFont(QFont("system",_r,700));
    painter.drawText(rect, _s[id].getText(),QTextOption(Qt::AlignCenter));
}

