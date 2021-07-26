#include "chartview.h"
#include "ui_chartview.h"

ChartView::ChartView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartView)
{
    ui->setupUi(this);
}

ChartView::~ChartView()
{
    delete ui;
}
