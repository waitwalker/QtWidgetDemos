#include "battery.h"
#include "ui_battery.h"
#include <QPainter>

Battery::Battery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battery)
{
    ui->setupUi(this);
}

void Battery::paintEvent(QPaintEvent *event) {
    qDebug()<<"第一次加载的时候会调用绘制函数";
    // 定义一个画笔
    QPainter painter(this);

    // 启动抗锯齿绘制
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    // 绘制边框
    drawBorder(&painter);

    //绘制背景
    //drawBg(&painter);
    //绘制头部
    //drawHead(&painter);
}

void Battery::drawBorder(QPainter *painter)
{
    painter->save();
    double headerWidth = 60.0;
    double batteryWidth = 600.0;

    // 绘制电池边框
    QPointF topLeft(2,2);
    QPointF bottomRight(batteryWidth,300);
    QRectF rectF = QRectF(topLeft,bottomRight);
    painter->setPen(QPen(QColor(0,0,255,100),2));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(rectF,10,15);
    painter->restore();
}

/*
void Battery::drawBorder(QPainter *painter)
{
    //绘制电池边框
    QPointF topLeft(borderWidth, borderWidth);
    QPointF bottomRight(batteryWidth, height() - borderWidth);
    batteryRect = QRectF(topLeft, bottomRight);

    painter->setPen(QPen(borderColorStart, borderWidth));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(batteryRect, borderRadius, borderRadius);

    painter->restore();
}

void Battery::drawBg(QPainter *painter)
{
    if (value == minValue) {
        return;
    }

    painter->save();

    QLinearGradient batteryGradient(QPointF(0, 0), QPointF(0, height()));
    if (currentValue <= alarmValue) {
        batteryGradient.setColorAt(0.0, alarmColorStart);
        batteryGradient.setColorAt(1.0, alarmColorEnd);
    } else {
        batteryGradient.setColorAt(0.0, normalColorStart);
        batteryGradient.setColorAt(1.0, normalColorEnd);
    }

    int margin = qMin(width(), height()) / 20;
    double unit = (batteryRect.width() - (margin * 2)) / 100;
    double width = currentValue * unit;
    QPointF topLeft(batteryRect.topLeft().x() + margin, batteryRect.topLeft().y() + margin);
    QPointF bottomRight(width + margin + borderWidth, batteryRect.bottomRight().y() - margin);
    QRectF rect(topLeft, bottomRight);

    painter->setPen(Qt::NoPen);
    painter->setBrush(batteryGradient);
    painter->drawRoundedRect(rect, bgRadius, bgRadius);

    painter->restore();
}

void Battery::drawHead(QPainter *painter)
{
    painter->save();

    QPointF headRectTopLeft(batteryRect.topRight().x(), height() / 3);
    QPointF headRectBottomRight(width(), height() - height() / 3);
    QRectF headRect(headRectTopLeft, headRectBottomRight);

    QLinearGradient headRectGradient(headRect.topLeft(), headRect.bottomLeft());
    headRectGradient.setColorAt(0.0, borderColorStart);
    headRectGradient.setColorAt(1.0, borderColorEnd);

    painter->setPen(Qt::NoPen);
    painter->setBrush(headRectGradient);
    painter->drawRoundedRect(headRect, headRadius, headRadius);

    painter->restore();
}
 *
 *
 *
 *
*/

Battery::~Battery()
{
    delete ui;
}
