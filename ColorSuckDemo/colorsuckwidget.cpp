#include "colorsuckwidget.h"
#include "ui_colorsuckwidget.h"

ColorSuckWidget::ColorSuckWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSuckWidget)
{
    ui->setupUi(this);
}

ColorSuckWidget::~ColorSuckWidget()
{
    delete ui;
}
