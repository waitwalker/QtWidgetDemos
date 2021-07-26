#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>

namespace Ui {
class ChartView;
}

class ChartView : public QWidget
{
    Q_OBJECT

public:
    explicit ChartView(QWidget *parent = nullptr);
    ~ChartView();

private:
    Ui::ChartView *ui;
};

#endif // CHARTVIEW_H
