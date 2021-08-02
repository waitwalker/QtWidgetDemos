#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 文件
    QMenu *fileMenu = menuBar()->addMenu("文件");

    QAction *newBookMarkAction = new QAction("新标签页",this);
    newBookMarkAction->setShortcut(QKeySequence("CTRL+SHIFT+T"));
    connect(newBookMarkAction,&QAction::triggered,[=](){
        qDebug()<<"新标签页";
    });
    fileMenu->addAction(newBookMarkAction);


    QMenu *recentMenu = fileMenu->addMenu("最近打开文件");

    QAction *recentFile1Action = new QAction("xxx1",this);
    QAction *recentFile2Action = new QAction("xxx2",this);
    QAction *recentFile3Action = new QAction("xxx3",this);
    QAction *recentFile4Action = new QAction("xxx4",this);
    QAction *recentFile5Action = new QAction("xxx5",this);

    recentMenu->addAction(recentFile1Action);
    recentMenu->addAction(recentFile2Action);
    recentMenu->addAction(recentFile3Action);
    recentMenu->addAction(recentFile4Action);
    recentMenu->addAction(recentFile5Action);

    QMenu *editMenu = menuBar()->addMenu("编辑");

    QMenu *viewMenu = menuBar()->addMenu("视图");

    QMenu *historyMenu = menuBar()->addMenu("历史记录");

    QMenu *bookmarkMenu = menuBar()->addMenu("书签页");

    QMenu *windowMenu = menuBar()->addMenu("窗口");

    QMenu *helpMenu = menuBar()->addMenu("帮助");


}

MainWindow::~MainWindow()
{
    delete ui;
}

