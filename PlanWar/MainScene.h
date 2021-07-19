#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>

namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

protected:
    virtual void closeEvent(QCloseEvent *event);
public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    // 初始化相关成员变量
    void initScene();

signals:
    // 要发送的信号 不需要实现
    void closeScene();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
