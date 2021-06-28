#include "battery.h"
#include "ui_battery.h"

Battery::Battery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battery)
{
    ui->setupUi(this);
}

Battery::~Battery()
{
    delete ui;
}
