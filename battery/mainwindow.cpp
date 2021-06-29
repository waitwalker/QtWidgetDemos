#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "battery.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 将widget 添加到主窗口上面
    Battery *batteryWidget = new Battery(this);
    this->setCentralWidget(batteryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

