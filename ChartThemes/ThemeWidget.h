#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

#include <QList>

class QComboBox;
class QCheckBox;

class Ui_ThemeWidgetForm;
class QCharView;
class QChart;

typedef QPair<QPointF, QString> Data;//重命名字典
typedef QList<Data> DataList;//重命名存储字典的数组
typedef QList<DataList> DataTable;//二维数组


namespace Ui {
class ThemeWidget;
}

class ThemeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThemeWidget(QWidget *parent = nullptr);
    ~ThemeWidget();

private:

    // 更新UI
    void updateUI();

private:
    // 产生随机表格数据
    DataTable generateRandomData(int listCount, int valueMax, int valueCount) const;
    // 计算主题Box
    void populateThemeBox();
    // 计算动画Box
    void populateAnimationBox();
    // 计算图例Box
    void populateLegendBox();
    // 连接信号
    void connectSignals();

    // 创建面积图
    QChart *createAreaChart() const;
    // 创建条形图
    QChart *createBarChart(int valueCount) const;
    // 创建饼状图
    QChart *createPieChart() const;
    // 创建折线图
    QChart *createLineChart() const;
    // 创建曲线图
    QChart *createSplineChart() const;
    // 创建散点图
    QChart *createScatterChart() const;

private:
    int m_listCount;
    int m_valueMax;
    int m_valueCount;
    QList<QCharView *> m_charts;
    DataTable m_dataTable;

    Ui_ThemeWidgetForm *m_ui;
};

#endif // THEMEWIDGET_H
