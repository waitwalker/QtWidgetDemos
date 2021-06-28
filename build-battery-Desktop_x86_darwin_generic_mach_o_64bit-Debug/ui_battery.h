/********************************************************************************
** Form generated from reading UI file 'battery.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERY_H
#define UI_BATTERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Battery
{
public:

    void setupUi(QWidget *Battery)
    {
        if (Battery->objectName().isEmpty())
            Battery->setObjectName(QString::fromUtf8("Battery"));
        Battery->resize(400, 300);

        retranslateUi(Battery);

        QMetaObject::connectSlotsByName(Battery);
    } // setupUi

    void retranslateUi(QWidget *Battery)
    {
        Battery->setWindowTitle(QCoreApplication::translate("Battery", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Battery: public Ui_Battery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERY_H
