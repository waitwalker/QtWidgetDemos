#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    // 在Qt中斜体字,表示虚函数
    // 绘制方法
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
