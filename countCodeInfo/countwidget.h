#ifndef COUNTWIDGET_H
#define COUNTWIDGET_H

#include <QWidget>

namespace Ui {
class CountWidget;
}

class CountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CountWidget(QWidget *parent = nullptr);
    ~CountWidget();

private:
    Ui::CountWidget *ui;
};

#endif // COUNTWIDGET_H
