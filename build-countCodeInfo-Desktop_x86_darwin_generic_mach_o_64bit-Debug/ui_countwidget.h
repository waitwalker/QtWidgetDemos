/********************************************************************************
** Form generated from reading UI file 'countwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTWIDGET_H
#define UI_COUNTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CountWidget
{
public:

    void setupUi(QWidget *CountWidget)
    {
        if (CountWidget->objectName().isEmpty())
            CountWidget->setObjectName(QString::fromUtf8("CountWidget"));
        CountWidget->resize(400, 300);

        retranslateUi(CountWidget);

        QMetaObject::connectSlotsByName(CountWidget);
    } // setupUi

    void retranslateUi(QWidget *CountWidget)
    {
        CountWidget->setWindowTitle(QCoreApplication::translate("CountWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CountWidget: public Ui_CountWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTWIDGET_H
