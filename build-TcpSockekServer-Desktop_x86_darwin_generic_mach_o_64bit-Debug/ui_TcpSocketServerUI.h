/********************************************************************************
** Form generated from reading UI file 'TcpSocketServerUI.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSOCKETSERVERUI_H
#define UI_TCPSOCKETSERVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpSocketServerUI
{
public:

    void setupUi(QWidget *TcpSocketServerUI)
    {
        if (TcpSocketServerUI->objectName().isEmpty())
            TcpSocketServerUI->setObjectName(QString::fromUtf8("TcpSocketServerUI"));
        TcpSocketServerUI->resize(400, 300);

        retranslateUi(TcpSocketServerUI);

        QMetaObject::connectSlotsByName(TcpSocketServerUI);
    } // setupUi

    void retranslateUi(QWidget *TcpSocketServerUI)
    {
        TcpSocketServerUI->setWindowTitle(QCoreApplication::translate("TcpSocketServerUI", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpSocketServerUI: public Ui_TcpSocketServerUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSOCKETSERVERUI_H
