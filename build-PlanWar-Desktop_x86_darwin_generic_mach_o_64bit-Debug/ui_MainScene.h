/********************************************************************************
** Form generated from reading UI file 'MainScene.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:

    void setupUi(QWidget *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QString::fromUtf8("MainScene"));
        MainScene->resize(400, 300);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QWidget *MainScene)
    {
        MainScene->setWindowTitle(QCoreApplication::translate("MainScene", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
