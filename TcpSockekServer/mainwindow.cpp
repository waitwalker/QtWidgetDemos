#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServerWidget = new TcpSocketServerUI();
    this->setCentralWidget(tcpServerWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

