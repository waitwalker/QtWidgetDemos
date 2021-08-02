#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{

    // 文件
    setupFileMenu();

    // 编辑
    setupEditMenu();

    // 视图
    setupViewMenu();

    // 历史记录
    setupHistoryMenu();

    // 书签
    setupBookmarkMenu();

    // 个人资料
    setupPersonDataMenu();

    // 标签页
    setupLabelPageMenu();

    // 窗口
    setupWindowMenu();

    // 帮助
    setupHelpMenu();

}

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = menuBar()->addMenu("文件");

    QAction *newBookMarkAction = new QAction("新标签页",this);
    newBookMarkAction->setShortcut(QKeySequence("CTRL+T"));
    connect(newBookMarkAction,&QAction::triggered,[=](){
        qDebug()<<"新标签页";
    });
    fileMenu->addAction(newBookMarkAction);

    QAction *openWindowAction = new QAction("打开新的窗口",this);
    openWindowAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    connect(openWindowAction,&QAction::triggered,[=](){
        qDebug()<<"打开新的窗口";
    });
    fileMenu->addAction(openWindowAction);

    QAction *openUnhistroyWindowMenu = new QAction("打开新的无痕式窗口",this);
    openUnhistroyWindowMenu->setShortcut(QKeySequence("CTRL+SHIFT+N"));
    connect(openUnhistroyWindowMenu,&QAction::triggered,[=](){
        qDebug()<<"打开新的无痕式窗口";
    });
    fileMenu->addAction(openUnhistroyWindowMenu);

    QAction *reopenBookMarkAction = new QAction("重新打开关闭的标签页",this);
    reopenBookMarkAction->setShortcut(QKeySequence("CTRL+SHIFT+T"));
    connect(reopenBookMarkAction,&QAction::triggered,[=](){
        qDebug()<<"重新打开关闭的标签页";
    });
    fileMenu->addAction(reopenBookMarkAction);

    QAction *openFileAction = new QAction("打开文件...",this);
    openFileAction->setShortcut(QKeySequence("CTRL+O"));
    connect(openFileAction,&QAction::triggered,[=](){
        qDebug()<<"打开文件...";
    });
    fileMenu->addAction(openFileAction);

    QAction *openLocationAction = new QAction("打开位置",this);
    openLocationAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    openLocationAction->setEnabled(false);
    connect(openLocationAction,&QAction::triggered,[=](){
        qDebug()<<"打开位置";
    });
    fileMenu->addAction(openLocationAction);

    fileMenu->addSeparator();

    QAction *closeWindowAction = new QAction("关闭窗口",this);
    closeWindowAction->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_W));
    connect(closeWindowAction,&QAction::triggered,[=](){
        qDebug()<<"关闭窗口";
    });
    fileMenu->addAction(closeWindowAction);

    QAction *closeBookmarkAction = new QAction("关闭标签页",this);
    closeBookmarkAction->setShortcut(QKeySequence("CTRL+W"));
    connect(closeBookmarkAction,&QAction::triggered,[=](){
        qDebug()<<"关闭标签页";
    });
    fileMenu->addAction(closeBookmarkAction);

    QAction *pageSaveAction = new QAction("页面存储为...",this);
    pageSaveAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    connect(pageSaveAction,&QAction::triggered,[=](){
        qDebug()<<"页面存储为...";
    });
    fileMenu->addAction(pageSaveAction);

    fileMenu->addSeparator();

    QMenu *shareMenu = fileMenu->addMenu("分享");

    QAction *emailAction = new QAction("通过电子邮件发送链接",this);
    emailAction->setIcon(QIcon(QPixmap(":/images/chrome_icon.png")));
    emailAction->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_I));
    shareMenu->addAction(emailAction);

    QAction *messageAction = new QAction("信息",this);
    messageAction->setIcon(QIcon(QPixmap(":/images/message_icon.png")));
    shareMenu->addAction(messageAction);

    QAction *airdropAction = new QAction("隔空投送",this);
    airdropAction->setIcon(QIcon(QPixmap(":/images/airdrop_icon.png")));
    shareMenu->addAction(airdropAction);

    QAction *memorandumAction = new QAction("备忘录",this);
    memorandumAction->setIcon(QIcon(QPixmap(":/images/memorandum_icon.png")));
    shareMenu->addAction(memorandumAction);

    QAction *simulatorAction = new QAction("Simulator",this);
    simulatorAction->setIcon(QIcon(QPixmap(":/images/simulator_icon.png")));
    shareMenu->addAction(simulatorAction);

    QAction *remindersAction = new QAction("提醒事项",this);
    remindersAction->setIcon(QIcon(QPixmap(":/images/reminders_icon.png")));
    shareMenu->addAction(remindersAction);

    QAction *wechatAction = new QAction("发送到微信",this);
    wechatAction->setIcon(QIcon(QPixmap(":/images/wechat_icon.png")));
    shareMenu->addAction(wechatAction);

    QAction *moreAction = new QAction("更多...",this);
    moreAction->setIcon(QIcon(QPixmap(":/images/more_icon.png")));
    shareMenu->addAction(moreAction);

    fileMenu->addSeparator();
    QAction *printerAction = new QAction("打印...",this);
    printerAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
    connect(printerAction,&QAction::triggered,[=](){
        qDebug()<<"打印...";
    });
    fileMenu->addAction(printerAction);
}

void MainWindow::setupEditMenu()
{
    QMenu *editMenu = menuBar()->addMenu("编辑");

    QAction *undoAction = new QAction("撤销", this);
    undoAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));
    connect(undoAction,&QAction::triggered,[=](){
        qDebug()<<"撤销";
    });
    editMenu->addAction(undoAction);

    QAction *redoAction = new QAction("重做", this);
    redoAction->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Z));
    connect(redoAction,&QAction::triggered,[=](){
        qDebug()<<"重做";
    });
    editMenu->addAction(redoAction);

    editMenu->addSeparator();
    QAction *shearAction = new QAction("剪切", this);
    shearAction->setShortcut(QKeySequence("CTRL+X"));
    connect(shearAction,&QAction::triggered,[=](){
        qDebug()<<"剪切";
    });
    editMenu->addAction(shearAction);

    QAction *copyAction = new QAction("复制", this);
    copyAction->setShortcut(QKeySequence("CTRL+C"));
    connect(copyAction,&QAction::triggered,[=](){
        qDebug()<<"复制";
    });
    editMenu->addAction(copyAction);

    QAction *pasteAction = new QAction("粘贴", this);
    pasteAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_V));
    connect(pasteAction,&QAction::triggered,[=](){
        qDebug()<<"粘贴";
    });
    editMenu->addAction(pasteAction);

    QAction *pasteSheetAction = new QAction("粘贴并匹配样式", this);
    pasteSheetAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_V));
    connect(pasteSheetAction,&QAction::triggered,[=](){
        qDebug()<<"粘贴并匹配样式";
    });
    editMenu->addAction(pasteSheetAction);

    QAction *deleteAction = new QAction("删除", this);
    connect(deleteAction,&QAction::triggered,[=](){
        qDebug()<<"删除";
    });
    editMenu->addAction(deleteAction);

    QAction *selectAllAction = new QAction("全选", this);
    selectAllAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_A));
    connect(selectAllAction,&QAction::triggered,[=](){
        qDebug()<<"全选";
    });
    editMenu->addAction(selectAllAction);
    editMenu->addSeparator();

    QMenu *findMenu = editMenu->addMenu("查找");
    QAction *searchPageAction = new QAction("搜索网页...", this);
    searchPageAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::Key_F));
    connect(searchPageAction,&QAction::triggered,[=](){
        qDebug()<<"搜索网页...";
    });
    findMenu->addAction(searchPageAction);

    QAction *findAction = new QAction("查找...", this);
    findAction->setShortcut(QKeySequence("CTRL+F"));
    connect(findAction,&QAction::triggered,[=](){
        qDebug()<<"查找...";
    });
    findMenu->addAction(findAction);

    QAction *findNextAction = new QAction("查找下一个", this);
    findNextAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_G));
    connect(findNextAction,&QAction::triggered,[=](){
        qDebug()<<"查找下一个";
    });
    findMenu->addAction(findNextAction);

    QAction *findPreviousAction = new QAction("查找上一个", this);
    findPreviousAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_G));
    connect(findPreviousAction,&QAction::triggered,[=](){
        qDebug()<<"查找上一个";
    });
    findMenu->addAction(findPreviousAction);

    QAction *findWithSelectAction = new QAction("使用所选内容查找", this);
    findWithSelectAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_E));
    connect(findWithSelectAction,&QAction::triggered,[=](){
        qDebug()<<"使用所选内容查找";
    });
    findMenu->addAction(findWithSelectAction);

    QAction *skipSelectAction = new QAction("跳到所选部分", this);
    skipSelectAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_J));
    skipSelectAction->setEnabled(false);
    connect(skipSelectAction,&QAction::triggered,[=](){
        qDebug()<<"跳到所选部分";
    });
    findMenu->addAction(skipSelectAction);

    QMenu *spellingAndGrammarMenu = editMenu->addMenu("拼写和语法");
    QAction *showSpellingAndGrammarAction =  new QAction("    显示拼写和语法",this);
    showSpellingAndGrammarAction->setShortcut(QKeySequence("CTRL+:"));
    connect(showSpellingAndGrammarAction,&QAction::triggered,[=](){
        qDebug()<<"显示拼写和缘分";
    });
    spellingAndGrammarMenu->addAction(showSpellingAndGrammarAction);

    QAction *nowAction =  new QAction("    立即检查",this);
    nowAction->setShortcut(QKeySequence("CTRL+;"));
    connect(nowAction,&QAction::triggered,[=](){
        qDebug()<<"立即检查";
    });
    spellingAndGrammarMenu->addAction(nowAction);

    QAction *checkAction =  new QAction("√  键入内容时检查拼写",this);
    //checkAction->setIcon(QIcon(QPixmap(":/images/input_icon.png")));
    connect(checkAction,&QAction::triggered,[=](){
        qDebug()<<"键入内容时检查拼写";
    });
    spellingAndGrammarMenu->addAction(checkAction);

    QAction *checkSpellingAction =  new QAction("    检查拼写和语法",this);
    checkSpellingAction->setEnabled(false);
    connect(checkSpellingAction,&QAction::triggered,[=](){
        qDebug()<<"检查拼写和语法";
    });
    spellingAndGrammarMenu->addAction(checkSpellingAction);

    QMenu *replaceMenu = editMenu->addMenu("替换");
    QAction *showReplaceAction = new QAction("    显示替换",this);
    connect(showReplaceAction,&QAction::triggered,[=](){
        qDebug()<<"显示替换";
    });
    replaceMenu->addAction(showReplaceAction);
    replaceMenu->addSeparator();

    QAction *smartQuoteAction = new QAction("    智能引号",this);
    smartQuoteAction->setEnabled(false);
    connect(smartQuoteAction,&QAction::triggered,[=](){
        qDebug()<<"智能引号";
    });
    replaceMenu->addAction(smartQuoteAction);

    QAction *smartDashAction = new QAction("    智能破折号",this);
    smartDashAction->setEnabled(false);
    connect(smartDashAction,&QAction::triggered,[=](){
        qDebug()<<"智能破折号";
    });
    replaceMenu->addAction(smartDashAction);

    QAction *textReplaceAction = new QAction("√  文本替换",this);
    textReplaceAction->setEnabled(false);
    connect(textReplaceAction,&QAction::triggered,[=](){
        qDebug()<<"√  文本替换";
    });
    replaceMenu->addAction(textReplaceAction);


    QMenu *voiceMenu = editMenu->addMenu("语音");
    QAction *startSpeakAction = new QAction("开始讲话",this);
    connect(startSpeakAction,&QAction::triggered,[=](){
        qDebug()<<"开始讲话";
    });
    voiceMenu->addAction(startSpeakAction);

    QAction *stopSpeakAction = new QAction("停止讲话",this);
    stopSpeakAction->setEnabled(false);
    connect(stopSpeakAction,&QAction::triggered,[=](){
        qDebug()<<"停止讲话";
    });
    voiceMenu->addAction(stopSpeakAction);

}

void MainWindow::setupViewMenu()
{

}

void MainWindow::setupHistoryMenu()
{

}

void MainWindow::setupBookmarkMenu()
{

}

void MainWindow::setupPersonDataMenu()
{

}

void MainWindow::setupLabelPageMenu()
{

}

void MainWindow::setupWindowMenu()
{

}

void MainWindow::setupHelpMenu()
{

}

