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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpSocketServerUI
{
public:
    QDateEdit *dateEdit;

    void setupUi(QWidget *TcpSocketServerUI)
    {
        if (TcpSocketServerUI->objectName().isEmpty())
            TcpSocketServerUI->setObjectName(QString::fromUtf8("TcpSocketServerUI"));
        TcpSocketServerUI->resize(400, 300);
        dateEdit = new QDateEdit(TcpSocketServerUI);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(100, 80, 171, 91));

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
