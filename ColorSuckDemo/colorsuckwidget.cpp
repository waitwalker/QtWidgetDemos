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
    // 网格布局
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11,11,11,11);

    // 垂直布局
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(0);

    labColor = new QLabel(this);
    labColor->setText("+");
    labColor->setStyleSheet("background-color:rgb(255,107,107);color:rgb(250,250,250)");
    label->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPixelSize(35);
    font.setBold(true);
    labColor->setFont(font);




}

ColorSuckWidget::~ColorSuckWidget()
{
    delete ui;
}

void ColorSuckWidget::mousePressEvent(QMouseEvent *event)
{

}

void ColorSuckWidget::mouseReleaseEvnet(QMouseEvent *event)
{

}

void ColorSuckWidget::showColorValue()
{

}
