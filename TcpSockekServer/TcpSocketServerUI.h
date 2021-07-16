#ifndef TCPSOCKETSERVERUI_H
#define TCPSOCKETSERVERUI_H

#include <QWidget>

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
};

#endif // TCPSOCKETSERVERUI_H
