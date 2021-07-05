#ifndef COLORSUCKWIDGET_H
#define COLORSUCKWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QClipboard>
#include <QLabel>
#include <QLineEdit>



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

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvnet(QMouseEvent *event);

private:
    Ui::ColorSuckWidget *ui;
    static ColorSuckWidget *instance;

    QClipboard *cp;
    bool pressed;
    QTimer *timer;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labColor;
    QLabel *label;
    QLabel *labWeb;
    QLineEdit *txtWeb;
    QLabel *labRGB;
    QLineEdit *txtRGB;
    QLabel *labPoint;
    QLineEdit *txtPoint;

private Q_SLOTS:

    void showColorValue();
};

#endif // COLORSUCKWIDGET_H
