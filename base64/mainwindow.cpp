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

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(button1);
    vLayout->addWidget(button2);

    widget->setLayout(vLayout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

