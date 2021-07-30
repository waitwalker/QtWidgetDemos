/********************************************************************************
** Form generated from reading UI file 'DownloadDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADDIALOG_H
#define UI_DOWNLOADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *urlLineEdit;
    QListWidget *urlListWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addUrlButton;
    QPushButton *clearUrlsButton;
    QPushButton *removeUrlButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DownloadDialog)
    {
        if (DownloadDialog->objectName().isEmpty())
            DownloadDialog->setObjectName(QString::fromUtf8("DownloadDialog"));
        DownloadDialog->resize(661, 438);
        horizontalLayoutWidget = new QWidget(DownloadDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 641, 361));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        urlLineEdit = new QLineEdit(horizontalLayoutWidget);
        urlLineEdit->setObjectName(QString::fromUtf8("urlLineEdit"));

        verticalLayout_2->addWidget(urlLineEdit);

        urlListWidget = new QListWidget(horizontalLayoutWidget);
        urlListWidget->setObjectName(QString::fromUtf8("urlListWidget"));

        verticalLayout_2->addWidget(urlListWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addUrlButton = new QPushButton(horizontalLayoutWidget);
        addUrlButton->setObjectName(QString::fromUtf8("addUrlButton"));

        verticalLayout->addWidget(addUrlButton);

        clearUrlsButton = new QPushButton(horizontalLayoutWidget);
        clearUrlsButton->setObjectName(QString::fromUtf8("clearUrlsButton"));

        verticalLayout->addWidget(clearUrlsButton);

        removeUrlButton = new QPushButton(horizontalLayoutWidget);
        removeUrlButton->setObjectName(QString::fromUtf8("removeUrlButton"));

        verticalLayout->addWidget(removeUrlButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        buttonBox = new QDialogButtonBox(DownloadDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(15, 393, 631, 41));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DownloadDialog);

        QMetaObject::connectSlotsByName(DownloadDialog);
    } // setupUi

    void retranslateUi(QDialog *DownloadDialog)
    {
        DownloadDialog->setWindowTitle(QCoreApplication::translate("DownloadDialog", "Dialog", nullptr));
        addUrlButton->setText(QCoreApplication::translate("DownloadDialog", "Add URL", nullptr));
        clearUrlsButton->setText(QCoreApplication::translate("DownloadDialog", "Clear", nullptr));
        removeUrlButton->setText(QCoreApplication::translate("DownloadDialog", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloadDialog: public Ui_DownloadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADDIALOG_H
