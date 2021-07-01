#include "colorsuckwidget.h"
#include "ui_colorsuckwidget.h"
// 单例模式
ColorSuckWidget *ColorSuckWidget::instance = 0;
ColorSuckWidget *ColorSuckWidget::sharedInstance()
{
    if (!instance) {
        // 同步机制
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!instance) {
            instance = new ColorSuckWidget;
        }
    }
    return instance;
}

ColorSuckWidget::ColorSuckWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSuckWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("颜色选择");
}

ColorSuckWidget::~ColorSuckWidget()
{
    delete ui;
}
