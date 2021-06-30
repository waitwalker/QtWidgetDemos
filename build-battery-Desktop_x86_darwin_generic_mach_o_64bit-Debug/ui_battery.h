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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Battery
{
public:
    QLabel *label;
    QSlider *horizontalSlider;

    void setupUi(QWidget *Battery)
    {
        if (Battery->objectName().isEmpty())
            Battery->setObjectName(QString::fromUtf8("Battery"));
        Battery->resize(806, 639);
        label = new QLabel(Battery);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 150, 60, 16));
        horizontalSlider = new QSlider(Battery);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(0, 450, 581, 101));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(Battery);

        QMetaObject::connectSlotsByName(Battery);
    } // setupUi

    void retranslateUi(QWidget *Battery)
    {
        Battery->setWindowTitle(QCoreApplication::translate("Battery", "Form", nullptr));
        label->setText(QCoreApplication::translate("Battery", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Battery: public Ui_Battery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERY_H
