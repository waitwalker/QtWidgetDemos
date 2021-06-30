#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    // 重写事件过滤虚函数
    virtual bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
