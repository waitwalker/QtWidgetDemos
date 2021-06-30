#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置背景透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    // 隐藏标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

    // 启动事件过滤
    ui->widget->installEventFilter(this);
    ui->widget->setStyleSheet(QString("background-image:url(:/image/%1.png)").arg(1));
}
/*
 *
    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            this->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
 *
*/

bool Widget:: eventFilter(QObject *watched, QEvent *evt) {
    static int index = 1;
    static QPoint mousePoint;
    static bool mousePressed = false;
    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    // 鼠标单击
    if (event->type() == QMouseEvent::MouseButtonPress) {
        // 单击左键切换图片
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - this->pos();
            if (index == 5) {
                index = 1;
            } else {
                index++;
            }
            ui->widget->setStyleSheet(QString("background-image:url(:/image/%1.png)").arg(index));
            return true;
        } else {
            // 单击右键 退出程序
            exit(0);
        }
    } else if (event->type() == QMouseEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            this->move(event->globalPos() - mousePoint);
            return true;
        }
    } else if (event->type() == QMouseEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    }

    return QWidget::eventFilter(watched,evt);
}

Widget::~Widget()
{
    delete ui;
}
