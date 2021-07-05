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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CountWidget
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *CountWidget)
    {
        if (CountWidget->objectName().isEmpty())
            CountWidget->setObjectName(QString::fromUtf8("CountWidget"));
        CountWidget->resize(400, 300);
        label = new QLabel(CountWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 60, 16));
        label_2 = new QLabel(CountWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 260, 60, 16));

        retranslateUi(CountWidget);

        QMetaObject::connectSlotsByName(CountWidget);
    } // setupUi

    void retranslateUi(QWidget *CountWidget)
    {
        CountWidget->setWindowTitle(QCoreApplication::translate("CountWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("CountWidget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("CountWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CountWidget: public Ui_CountWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTWIDGET_H
