#include "ThemeWidget.h"
#include "ui_ThemeWidget.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QGridLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QLabel>
#include <QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QApplication>
#include <QtCharts/QValueAxis>



ThemeWidget::ThemeWidget(QWidget *parent) :
    QWidget(parent),
    m_listCount(3),
    m_valueMax(10),
    m_valueCount(7),
    m_dataTable(generateRandomData(m_listCount,m_valueMax,m_valueCount)),
    m_ui(new Ui_ThemeWidgetForm)
{
    m_ui->setupUi(this);
}

ThemeWidget::~ThemeWidget()
{
    delete m_ui;
}

DataTable ThemeWidget::generateRandomData(int listCount, int valueMax, int valueCount) const
{
    DataTable dataTable;
    for (int i = 0; i < listCount; i++) {
        DataList dataList;
        qreal yValue(0);
        for (int j = 0;j < valueCount ;j++ ) {
            yValue = yValue + QRandomGenerator::global()->bounded(valueMax / (qreal)valueCount);
            QPointF value((j + QRandomGenerator::global()->generateDouble()) * ((qreal)m_valueMax /(qreal)valueCount), yValue);
            QString label = "Slice" + QString::number(i) + ":" + QString::number(j);
            dataList.append(Data(value,label));
        }
        dataTable<<dataList;
    }
    return dataTable;
}

void ThemeWidget::populateThemeBox() {
    m_ui->themeComboBox->addItem();
}
