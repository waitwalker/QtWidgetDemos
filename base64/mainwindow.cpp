#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1)创建一个widget
    QWidget *widget = new QWidget;

    QPushButton *button1 = new QPushButton("button1");
    QPushButton *button2 = new QPushButton("button2");

    QPushButton *button3 = new QPushButton("button3");
    QPushButton *button4 = new QPushButton("button4");


    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    QHBoxLayout *hLayout = new QHBoxLayout;

    //void QLayout::setContentsMargins(int left, int top, int right, int bottom)
    vLayout->setContentsMargins(100,30,200,100);

    // 设置控件之间的间距
    //vLayout->setSpacing(10);
    // 居中显示 上下分别添加一个弹簧
    // 居下显示
    vLayout->addStretch();
    hLayout->addWidget(button1);
    hLayout->addWidget(button2);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(button3);
    vLayout->addWidget(button4);
    //  居上显示 添加一个弹框
    vLayout->addStretch();

    widget->setLayout(vLayout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

