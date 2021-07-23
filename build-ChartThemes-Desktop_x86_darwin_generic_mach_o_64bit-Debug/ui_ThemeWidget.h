/********************************************************************************
** Form generated from reading UI file 'ThemeWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEWIDGET_H
#define UI_THEMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeWidget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *themeLabel;
    QComboBox *themeComboBox;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ThemeWidget)
    {
        if (ThemeWidget->objectName().isEmpty())
            ThemeWidget->setObjectName(QString::fromUtf8("ThemeWidget"));
        ThemeWidget->resize(779, 476);
        horizontalLayoutWidget = new QWidget(ThemeWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 781, 471));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        themeLabel = new QLabel(horizontalLayoutWidget);
        themeLabel->setObjectName(QString::fromUtf8("themeLabel"));

        horizontalLayout->addWidget(themeLabel);

        themeComboBox = new QComboBox(horizontalLayoutWidget);
        themeComboBox->setObjectName(QString::fromUtf8("themeComboBox"));

        horizontalLayout->addWidget(themeComboBox);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(horizontalLayoutWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ThemeWidget);

        QMetaObject::connectSlotsByName(ThemeWidget);
    } // setupUi

    void retranslateUi(QWidget *ThemeWidget)
    {
        ThemeWidget->setWindowTitle(QCoreApplication::translate("ThemeWidget", "Form", nullptr));
        themeLabel->setText(QCoreApplication::translate("ThemeWidget", "Theme", nullptr));
        label->setText(QCoreApplication::translate("ThemeWidget", "Animation:", nullptr));
        label_2->setText(QCoreApplication::translate("ThemeWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThemeWidget: public Ui_ThemeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEWIDGET_H
