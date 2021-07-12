#include "MyWidget.h"
#include "ui_MyWidget.h"
#include <QPainter>
#include <QMouseEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    // 创建画笔
    QPainter painter(this);

    // 设置画笔
    QPen pen;
    pen.setColor(QColor(255,0,0));

#if 0


    // 设置填充相关属性字段

    // 画直线
    painter.drawLine(QPoint(0,0), QPoint(200,200));
    painter.setBrush(QColor(255, 160, 90));
    painter.setPen(pen);


    // 绘制文本
    painter.drawText(200,200,"HelloQt");

    // 绘制圆圈
    painter.drawEllipse(QPoint(250,250),50,50);
#endif
    painter.drawEllipse(_point,30,30);
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    // 获取鼠标点击的位置
    _point = event->pos();
    //update();
    repaint();
}
