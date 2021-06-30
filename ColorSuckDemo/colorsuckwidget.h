#ifndef COLORSUCKWIDGET_H
#define COLORSUCKWIDGET_H

#include <QWidget>

namespace Ui {
class ColorSuckWidget;
}

class ColorSuckWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSuckWidget(QWidget *parent = nullptr);
    ~ColorSuckWidget();

private:
    Ui::ColorSuckWidget *ui;
};

#endif // COLORSUCKWIDGET_H
