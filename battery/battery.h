#ifndef BATTERY_H
#define BATTERY_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Battery;
}

class Battery : public QWidget
{
    Q_OBJECT

public:
    explicit Battery(QWidget *parent = nullptr);

    ~Battery();
    // 重写父类中的绘制虚函数
    virtual void paintEvent(QPaintEvent *event);


private:
    Ui::Battery *ui;

    // 绘制边框
    void drawBorder(QPainter *painter);

    // 绘制背景
    void drawBackground(QPainter *painter);

    // 绘制电池头部
    void drawHeader(QPainter *painter);
};

#endif // BATTERY_H
