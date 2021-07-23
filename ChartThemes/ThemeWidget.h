#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QWidget>

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
    Ui::ThemeWidget *ui;
};

#endif // THEMEWIDGET_H
