#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>

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
    QLineEdit *lineEdit = new QLineEdit;

    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *lineContainer = new QHBoxLayout;
    QHBoxLayout *buttonContainer = new QHBoxLayout;


    buttonContainer->addWidget(button1);
    buttonContainer->addWidget(button2);
    lineContainer->addWidget(lineEdit);
    hLayout->addLayout(lineContainer);
    hLayout->addLayout(buttonContainer);
    hLayout->setStretchFactor(lineContainer,1);
    hLayout->setStretchFactor(buttonContainer,1);

    //void QLayout::setContentsMargins(int left, int top, int right, int bottom)
    vLayout->setContentsMargins(30,30,30,100);

    // 设置控件之间的间距
    //vLayout->setSpacing(10);
    // 居中显示 上下分别添加一个弹簧
    // 居下显示 在上面添加一个弹簧
    //vLayout->addStretch();
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

