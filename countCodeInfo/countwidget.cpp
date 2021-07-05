#include "countwidget.h"
#include "ui_countwidget.h"

CountWidget::CountWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountWidget)
{
    ui->setupUi(this);
}

CountWidget::~CountWidget()
{
    delete ui;
}
