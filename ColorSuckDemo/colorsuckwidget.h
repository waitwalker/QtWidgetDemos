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
    static ColorSuckWidget *sharedInstance();
    explicit ColorSuckWidget(QWidget *parent = nullptr);
    ~ColorSuckWidget();

private:
    Ui::ColorSuckWidget *ui;
    static ColorSuckWidget *instance;
};

#endif // COLORSUCKWIDGET_H
