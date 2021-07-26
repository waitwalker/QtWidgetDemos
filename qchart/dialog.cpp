#include "dialog.h"
#include "ui_dialog.h"
#include <QtCharts>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // 创建QChartView对象
    QChartView *chartView;

    // QChartView 对象载入面积图
    chartView = new QChartView(createAreaChart());

    ui->verticalLayout->insertWidget(0,chartView);

}

Dialog::~Dialog()
{
    delete ui;
}

QChart *Dialog::createAreaChart() const
{

    QChart *chart = new QChart();
    chart->setTitle("面积图演示");

    QLineSeries *series = new QLineSeries(chart);
    series->setName("A店铺接收单数");
    series->append(0,8);
    series->append(1,10);
    series->append(2,12);
    series->append(3,17);
    series->append(4,19);
    series->append(5,18);
    series->append(6,20);

    QLineSeries *seriesB = new QLineSeries(chart);
    seriesB->setName("B店铺接单数");
    seriesB->append(0,1);
    seriesB->append(1,4);
    seriesB->append(2,5);
    seriesB->append(3,3);
    seriesB->append(4,11);
    seriesB->append(5,16);
    seriesB->append(6,19);


    QAreaSeries *areaA = new QAreaSeries(series,0);
    QAreaSeries *areaB = new QAreaSeries(seriesB,series);
    areaA->setName("A区域");
    areaB->setName("B区域");
    chart->addSeries(areaA);
    chart->addSeries(areaB);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0,6);
    chart->axes(Qt::Vertical).first()->setRange(0,20);


    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f ");
    chart->setTheme(QChart::ChartThemeBrownSand);
    return chart;
}

