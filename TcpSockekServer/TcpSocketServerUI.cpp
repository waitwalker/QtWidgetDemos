#include "TcpSocketServerUI.h"
#include "ui_TcpSocketServerUI.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>

TcpSocketServerUI::TcpSocketServerUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpSocketServerUI)
{
    ui->setupUi(this);

    QVBoxLayout *vLayout = new QVBoxLayout(this);

    QTextEdit *receiveEdit = new QTextEdit();
    receiveEdit->setText("收到的信息:");
    vLayout->addWidget(receiveEdit);

    QTextEdit *sendEdit = new QTextEdit();
    sendEdit->setText("发送的信息:");
    vLayout->addWidget(sendEdit);

    QHBoxLayout *hLayout = new QHBoxLayout();
    vLayout->addLayout(hLayout);

    QPushButton *sendButton = new QPushButton("发送");
    hLayout->addWidget(sendButton);

    QPushButton *closeButton = new QPushButton("关闭");
    hLayout->addWidget(closeButton);

}

TcpSocketServerUI::~TcpSocketServerUI()
{
    delete ui;
}
