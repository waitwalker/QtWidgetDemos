#include "HomeWindow.h"
#include "ui_HomeWindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Home");
    this->resize(800,600);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
