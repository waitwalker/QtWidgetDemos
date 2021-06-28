#ifndef BATTERY_H
#define BATTERY_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Battery;
}

class Battery : public QWidget
{
    Q_OBJECT

public:
    explicit Battery(QWidget *parent = nullptr);

    ~Battery();

private:
    Ui::Battery *ui;
};

#endif // BATTERY_H
