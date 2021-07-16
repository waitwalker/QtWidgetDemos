#include "TcpSocketServerUI.h"
#include "ui_TcpSocketServerUI.h"


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

    hLayout->addSpacing(30);
    QPushButton *createButton = new QPushButton("创建");
    hLayout->addWidget(createButton, 2);


    //QSpacerItem *spaceItem = new QSpacerItem(40, 20,QSizePolicy::Expanding);
    //hLayout->addSpacerItem(spaceItem);
    hLayout->addStretch(2);
    QPushButton *sendButton = new QPushButton("发送");
    hLayout->addWidget(sendButton, 2);


    hLayout->addStretch(2);

    QPushButton *closeButton = new QPushButton("关闭");
    hLayout->addWidget(closeButton, 2);
    hLayout->addSpacing(30);

    this->receiveEdit = receiveEdit;
    this->sendEdit = sendEdit;

    this->createButton = createButton;
    this->sendButton = sendButton;
    this->closeButton = closeButton;


    connect(this->createButton,&QPushButton::clicked,[=](){
        this->pTcpServer = NULL;
        this->pTcpSocket = NULL;

        // 创建server
        pTcpServer = new QTcpServer(this);

        // 绑定ip&监听端口
        bool isListeningSuccess = pTcpServer->listen(QHostAddress::Any, 10007);
        qDebug()<<"监听端口状态:"<<isListeningSuccess;

        if (isListeningSuccess) {
            // 建立连接
            connect(this->pTcpServer,&QTcpServer::newConnection,[=](){
                // 取出建立连接好的套接字
                pTcpSocket = pTcpServer->nextPendingConnection();

                // 获取客户端的IP和端口
                QString ip = pTcpSocket->peerAddress().toString();
                qint16 port = pTcpSocket->peerPort();
                QString tmp = QString("[%1 %2]:The client connection is successful.").arg(ip).arg(port);
                this->receiveEdit->setText(tmp);

                // 读取消息
                connect(pTcpSocket,&QTcpSocket::readyRead,[=](){
                    QByteArray array = pTcpSocket->readAll();
                    this->receiveEdit->append("[Client:]" + array);

                });
            });

            connect(this->sendButton,&QPushButton::pressed,[=](){
                QString str = "[Server:]" + this->sendEdit->toPlainText();
                this->receiveEdit->append(str);
            });

            // server给client发消息
            connect(this->sendButton,&QPushButton::clicked,[=](){
                QString str = this->sendEdit->toPlainText();
                pTcpSocket->write(str.toUtf8().data());
            });

            connect(this->closeButton,&QPushButton::clicked,[=](){
                this->pTcpSocket->disconnectFromHost();
                this->pTcpSocket->close();
            });
        }
    });


}

TcpSocketServerUI::~TcpSocketServerUI()
{
    delete ui;
}
