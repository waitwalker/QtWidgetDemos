#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCharts>


QT_BEGIN_NAMESPACE

namespace Ui { class Dialog; }
QT_END_NAMESPACE



class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QChart *createAreaChart() const;

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
