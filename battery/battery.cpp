#include "battery.h"
#include "ui_battery.h"
#include <QPainter>
#include <QSlider>

Battery::Battery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battery)
{
    ui->setupUi(this);

    currentWidth = (600 - 20) * 0.3;

    ui->label->setText("电池电量:30");
    ui->horizontalSlider->setValue(30);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setMinimum(0);

    connect(ui->horizontalSlider,&QSlider::valueChanged,[=](int value){
        qDebug()<<"current value:"<<value;
        currentWidth = (600 - 20) * value / 100;
        QString str = QString("电池电量:") + QString::number(value);

        ui->label->setText(str);
        this->update();
    });
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
    drawBackground(&painter);

    //绘制头部
    drawHeader(&painter);
}

double Battery::getCurrentWidth() const
{
    return currentWidth;
}

void Battery::setCurrentWidth(double newCurrentWidth)
{
    currentWidth = newCurrentWidth;
}

void Battery::drawBorder(QPainter *painter)
{
    painter->save();
    double batteryWidth = 600.0;

    // 绘制电池边框
    QPointF topLeft(2,2);
    QPointF bottomRight(batteryWidth,300);
    QRectF rectF = QRectF(topLeft,bottomRight);
    painter->setPen(QPen(QColor(255,255,255,100),10));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(rectF,10,15);
    painter->restore();
}

void Battery::drawBackground(QPainter *painter)
{
    painter->save();

    // 绘制电池背景
    QRectF rectF = QRectF(10, 10, currentWidth, 300 - 20);
    painter->setPen(QPen(QColor(5,100,155,100),5));
    QBrush brush;
    if (currentWidth / (600 - 20) > 0.25) {
        brush.setColor(QColor(0,255,0,120));
    } else {
        brush.setColor(QColor(204, 38, 38));
    }

    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(rectF,10,15);
    painter->restore();
}

void Battery::drawHeader(QPainter *painter)
{
    painter->save();
    double batteryWidth = 50.0;

    // 绘制电池头
    QPointF topLeft(600 + 5,(300 - 100) / 2);
    QPointF bottomRight(600 + batteryWidth + 5,(300 - 100) / 2 +100);
    QRectF rectF = QRectF(topLeft,bottomRight);
    QBrush brush;
    brush.setColor(QColor(255,255,255,100));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(rectF,10,15);
    painter->restore();
}

Battery::~Battery()
{
    delete ui;
}
