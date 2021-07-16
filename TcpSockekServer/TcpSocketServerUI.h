#ifndef TCPSOCKETSERVERUI_H
#define TCPSOCKETSERVERUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QTcpServer>
#include <QTcpSocket>


namespace Ui {
class TcpSocketServerUI;
}

class TcpSocketServerUI : public QWidget
{
    Q_OBJECT

public:
    explicit TcpSocketServerUI(QWidget *parent = nullptr);
    ~TcpSocketServerUI();

private:
    Ui::TcpSocketServerUI *ui;

    QTextEdit *receiveEdit;
    QTextEdit *sendEdit;

    QPushButton *createButton;
    QPushButton *sendButton;
    QPushButton *closeButton;

    QTcpServer *pTcpServer;
    QTcpSocket *pTcpSocket;

};

#endif // TCPSOCKETSERVERUI_H
