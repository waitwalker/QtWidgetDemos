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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeWidgetForm
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *themeLabel;
    QComboBox *themeComboBox;
    QLabel *animationLabel;
    QComboBox *animationComboBox;
    QLabel *legendLabel;
    QComboBox *legendComboBox;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ThemeWidgetForm)
    {
        if (ThemeWidgetForm->objectName().isEmpty())
            ThemeWidgetForm->setObjectName(QString::fromUtf8("ThemeWidgetForm"));
        ThemeWidgetForm->resize(778, 522);
        horizontalLayoutWidget = new QWidget(ThemeWidgetForm);
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

        animationLabel = new QLabel(horizontalLayoutWidget);
        animationLabel->setObjectName(QString::fromUtf8("animationLabel"));

        horizontalLayout->addWidget(animationLabel);

        animationComboBox = new QComboBox(horizontalLayoutWidget);
        animationComboBox->setObjectName(QString::fromUtf8("animationComboBox"));

        horizontalLayout->addWidget(animationComboBox);

        legendLabel = new QLabel(horizontalLayoutWidget);
        legendLabel->setObjectName(QString::fromUtf8("legendLabel"));

        horizontalLayout->addWidget(legendLabel);

        legendComboBox = new QComboBox(horizontalLayoutWidget);
        legendComboBox->setObjectName(QString::fromUtf8("legendComboBox"));

        horizontalLayout->addWidget(legendComboBox);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ThemeWidgetForm);

        QMetaObject::connectSlotsByName(ThemeWidgetForm);
    } // setupUi

    void retranslateUi(QWidget *ThemeWidgetForm)
    {
        ThemeWidgetForm->setWindowTitle(QCoreApplication::translate("ThemeWidgetForm", "Form", nullptr));
        themeLabel->setText(QCoreApplication::translate("ThemeWidgetForm", "Theme", nullptr));
        animationLabel->setText(QCoreApplication::translate("ThemeWidgetForm", "Animation:", nullptr));
        legendLabel->setText(QCoreApplication::translate("ThemeWidgetForm", "Legend:", nullptr));
        checkBox->setText(QCoreApplication::translate("ThemeWidgetForm", "antialiasCheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThemeWidgetForm: public Ui_ThemeWidgetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEWIDGET_H
