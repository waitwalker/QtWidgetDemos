/********************************************************************************
** Form generated from reading UI file 'colorsuckwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSUCKWIDGET_H
#define UI_COLORSUCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorSuckWidget
{
public:

    void setupUi(QWidget *ColorSuckWidget)
    {
        if (ColorSuckWidget->objectName().isEmpty())
            ColorSuckWidget->setObjectName(QString::fromUtf8("ColorSuckWidget"));
        ColorSuckWidget->resize(400, 300);

        retranslateUi(ColorSuckWidget);

        QMetaObject::connectSlotsByName(ColorSuckWidget);
    } // setupUi

    void retranslateUi(QWidget *ColorSuckWidget)
    {
        ColorSuckWidget->setWindowTitle(QCoreApplication::translate("ColorSuckWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorSuckWidget: public Ui_ColorSuckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSUCKWIDGET_H
