#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SearchAction.h"
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
    // About
    setupFirstHelpMenu();

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

void MainWindow::setupFirstHelpMenu()
{
    QMenu *helpAboutMenu = new QMenu(this);
    QAction *aboutAction = new QAction("&About",this);
    connect(aboutAction,&QAction::triggered,[=](){
        qDebug()<<"About";
    });
    helpAboutMenu->addAction(aboutAction);
    menuBar()->addMenu(helpAboutMenu)->setText("&Help");

    QMenu *helpPreferenceMenu = new QMenu(this);
    QAction *preferenceAction = new QAction("&Preference",this);
    connect(preferenceAction,&QAction::triggered,[=](){
        qDebug()<<"Preference";
    });
    helpPreferenceMenu->addAction(preferenceAction);
    menuBar()->addMenu(helpPreferenceMenu)->setText("&Help");

    menuBar()->setNativeMenuBar(true);

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
    QMenu *viewMenu = menuBar()->addMenu("视图");
    QAction *alwaysShowAction = new QAction("√  总是显示书签栏");
    alwaysShowAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_B));
    connect(alwaysShowAction,&QAction::triggered,[=](){
        qDebug()<<"√  总是显示书签栏";
    });
    viewMenu->addAction(alwaysShowAction);

    QAction *alwaysFullScreenShowAction = new QAction("√  在全屏模式下始终显示书签栏");
    alwaysFullScreenShowAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_F));
    connect(alwaysFullScreenShowAction,&QAction::triggered,[=](){
        qDebug()<<"√  在全屏模式下始终显示书签栏";
    });
    viewMenu->addAction(alwaysFullScreenShowAction);

    QAction *alwaysFullAddressShowAction = new QAction("    总是显示完整网址");
    connect(alwaysFullAddressShowAction,&QAction::triggered,[=](){
        qDebug()<<"总是显示完整网址";
    });
    viewMenu->addAction(alwaysFullAddressShowAction);

    viewMenu->addSeparator();

    QAction *stopAction = new QAction("    停止");
    stopAction->setShortcut(QKeySequence("CTRL+."));
    stopAction->setEnabled(false);
    connect(stopAction,&QAction::triggered,[=](){
        qDebug()<<"停止";
    });
    viewMenu->addAction(stopAction);

    QAction *forceAction = new QAction("    强制重新加载此页");
    forceAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_R));
    connect(forceAction,&QAction::triggered,[=](){
        qDebug()<<"强制重新加载此页";
    });
    viewMenu->addAction(forceAction);
    viewMenu->addSeparator();

    QAction *fullScreenAction = new QAction("    进入全屏幕");
    fullScreenAction->setShortcut(QKeySequence(Qt::UpArrow|Qt::CTRL|Qt::Key_F));
    connect(fullScreenAction,&QAction::triggered,[=](){
        qDebug()<<"进入全屏幕";
    });
    viewMenu->addAction(forceAction);

    QAction *realSizeAction = new QAction("    实际大小");
    realSizeAction->setShortcut(QKeySequence("CTRL+O"));
    realSizeAction->setEnabled(false);
    connect(realSizeAction,&QAction::triggered,[=](){
        qDebug()<<"实际大小";
    });
    viewMenu->addAction(realSizeAction);

    QAction *increaseAction = new QAction("    放大");
    increaseAction->setShortcut(QKeySequence("CTRL++"));
    connect(increaseAction,&QAction::triggered,[=](){
        qDebug()<<"放大";
    });
    viewMenu->addAction(increaseAction);

    QAction *decreaseAction = new QAction("    缩小");
    decreaseAction->setShortcut(QKeySequence("CTRL+-"));
    connect(decreaseAction,&QAction::triggered,[=](){
        qDebug()<<"缩小";
    });
    viewMenu->addAction(decreaseAction);
    viewMenu->addSeparator();

    QAction *throwAction = new QAction("    投射...");
    connect(throwAction,&QAction::triggered,[=](){
        qDebug()<<"缩小";
    });
    viewMenu->addAction(throwAction);
    viewMenu->addSeparator();

    QMenu *developerMenu = viewMenu->addMenu("    开发者");

    QAction *showCodeAction = new QAction("显示源代码");
    showCodeAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::Key_U));
    connect(showCodeAction,&QAction::triggered,[=](){
        qDebug()<<"显示源代码";
    });
    developerMenu->addAction(showCodeAction);

    QAction *developerToolAction = new QAction("开发者工具");
    developerToolAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::Key_I));
    connect(developerToolAction,&QAction::triggered,[=](){
        qDebug()<<"开发者工具";
    });
    developerMenu->addAction(developerToolAction);

    QAction *checkElementAction = new QAction("检查元素");
    checkElementAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::Key_C));
    connect(checkElementAction,&QAction::triggered,[=](){
        qDebug()<<"检查元素";
    });
    developerMenu->addAction(checkElementAction);

    QAction *javaScriptAction = new QAction("JavaScript控制台");
    javaScriptAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::Key_J));
    connect(javaScriptAction,&QAction::triggered,[=](){
        qDebug()<<"JavaScript控制台";
    });
    developerMenu->addAction(javaScriptAction);

    QAction *allowAppleJavaScriptAction = new QAction("允许Apple事件中的JavaScript");
    connect(allowAppleJavaScriptAction,&QAction::triggered,[=](){
        qDebug()<<"允许Apple事件中的JavaScript";
    });
    developerMenu->addAction(allowAppleJavaScriptAction);
}

void MainWindow::setupHistoryMenu()
{
    QMenu *historyMenu = menuBar()->addMenu("历史记录");

    QAction *homePageAction = new QAction("首页",this);
    homePageAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_H));
    connect(homePageAction,&QAction::triggered,[=](){
        qDebug()<<"首页";
    });
    historyMenu->addAction(homePageAction);

    QAction *backAction = new QAction("返回",this);
    backAction->setShortcut(QKeySequence("CTRL+["));
    connect(backAction,&QAction::triggered,[=](){
        qDebug()<<"返回";
    });
    historyMenu->addAction(backAction);

    QAction *forwardAction = new QAction("前进",this);
    forwardAction->setShortcut(QKeySequence("CTRL+]"));
    forwardAction->setEnabled(false);
    connect(forwardAction,&QAction::triggered,[=](){
        qDebug()<<"前进";
    });
    historyMenu->addAction(forwardAction);
    historyMenu->addSeparator();

    QAction *recentLabelAction = new QAction("最近关闭的标签页",this);
    recentLabelAction->setEnabled(false);
    connect(recentLabelAction,&QAction::triggered,[=](){
        qDebug()<<"最近关闭的标签页";
    });
    historyMenu->addAction(recentLabelAction);
    historyMenu->addSeparator();

    QAction *recentHistoryAction = new QAction("最近访问过的内容",this);
    recentHistoryAction->setEnabled(false);
    connect(recentHistoryAction,&QAction::triggered,[=](){
        qDebug()<<"最近访问过的内容";
    });
    historyMenu->addAction(recentHistoryAction);
    historyMenu->addSeparator();

    QAction *allHistoryAction = new QAction("显示全部历史记录",this);
    allHistoryAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_Y));
    allHistoryAction->setIcon(QIcon(QPixmap(":/images/all_history_icon.png")));
    connect(allHistoryAction,&QAction::triggered,[=](){
        qDebug()<<"显示全部历史记录";
    });
    historyMenu->addAction(allHistoryAction);
}

void MainWindow::setupBookmarkMenu()
{
    QMenu *bookmarkMenu = menuBar()->addMenu("书签");
    QAction *bookmarkManagerAction = new QAction("书签管理器");
    bookmarkManagerAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::Key_B));
    connect(bookmarkManagerAction,&QAction::triggered,[=](){
        qDebug()<<"书签管理器";
    });
    bookmarkMenu->addAction(bookmarkManagerAction);

    QAction *addBookmarkForLabelAction = new QAction("为此标签页添加书签...");
    addBookmarkForLabelAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_D));
    connect(addBookmarkForLabelAction,&QAction::triggered,[=](){
        qDebug()<<"为此标签页添加书签...";
    });
    bookmarkMenu->addAction(addBookmarkForLabelAction);

    QAction *addBookmarkForAllAction = new QAction("为所有标签页添加书签...");
    addBookmarkForAllAction->setShortcut(QKeySequence(Qt::CTRL|Qt::SHIFT|Qt::Key_D));
    connect(addBookmarkForAllAction,&QAction::triggered,[=](){
        qDebug()<<"为所有标签页添加书签...";
    });
    bookmarkMenu->addAction(addBookmarkForAllAction);
}

void MainWindow::setupPersonDataMenu()
{
    QMenu *personDataMenu = menuBar()->addMenu("个人资料");
    QAction *userAction = new QAction("上海的风",this);
    userAction->setIcon(QIcon(QPixmap(":/images/user_icon.png")));
    connect(userAction,&QAction::triggered,[=](){
        qDebug()<<"上海的风";
    });
    personDataMenu->addAction(userAction);
    personDataMenu->addSeparator();

    QAction *editAction = new QAction("编辑...",this);
    connect(editAction,&QAction::triggered,[=](){
        qDebug()<<"编辑...";
    });
    personDataMenu->addAction(editAction);
    personDataMenu->addSeparator();

    QAction *addInfoAction = new QAction("添加个人资料...",this);
    connect(addInfoAction,&QAction::triggered,[=](){
        qDebug()<<"添加个人资料...";
    });
    personDataMenu->addAction(addInfoAction);

}

void MainWindow::setupLabelPageMenu()
{
    QMenu *labelPageMenu = menuBar()->addMenu("标签页");

    QAction *addLabelRightAction = new QAction("在右侧新增标签页");
    connect(addLabelRightAction,&QAction::triggered,[=](){
        qDebug()<<"在右侧新增标签页";
    });
    labelPageMenu->addAction(addLabelRightAction);

    QAction *selectNextLabelAction = new QAction("选择下一个标签");
    selectNextLabelAction->setShortcut(QKeySequence("CTRL+→"));
    connect(selectNextLabelAction,&QAction::triggered,[=](){
        qDebug()<<"选择下一个标签";
    });
    labelPageMenu->addAction(selectNextLabelAction);

    QAction *selectPreviousLabelAction = new QAction("选择上一个标签");
    selectPreviousLabelAction->setShortcut(QKeySequence("CTRL+SHIFT+→"));
    connect(selectPreviousLabelAction,&QAction::triggered,[=](){
        qDebug()<<"选择上一个标签";
    });
    labelPageMenu->addAction(selectPreviousLabelAction);


    QAction *copyLabelAction = new QAction("赋值标签");
    connect(copyLabelAction,&QAction::triggered,[=](){
        qDebug()<<"赋值标签";
    });
    labelPageMenu->addAction(copyLabelAction);

    QAction *shutdownVoiceAction = new QAction("将单个网站静音");
    connect(shutdownVoiceAction,&QAction::triggered,[=](){
        qDebug()<<"将单个网站静音";
    });
    labelPageMenu->addAction(shutdownVoiceAction);

    QAction *fixLabelAction = new QAction("固定标签页");
    connect(fixLabelAction,&QAction::triggered,[=](){
        qDebug()<<"固定标签页";
    });
    labelPageMenu->addAction(fixLabelAction);

    QAction *createLabelGroupAction = new QAction("为标签页建组");
    connect(createLabelGroupAction,&QAction::triggered,[=](){
        qDebug()<<"为标签页建组";
    });
    labelPageMenu->addAction(createLabelGroupAction);

    QAction *closeOtherLabelAction = new QAction("关闭其他标签页");
    connect(closeOtherLabelAction,&QAction::triggered,[=](){
        qDebug()<<"关闭其他标签页";
    });
    labelPageMenu->addAction(closeOtherLabelAction);

    QAction *closeRightLabelAction = new QAction("关闭右侧标签页");
    connect(closeRightLabelAction,&QAction::triggered,[=](){
        qDebug()<<"关闭右侧标签页";
    });
    labelPageMenu->addAction(closeRightLabelAction);

    QAction *addLabelToNewWindowAction = new QAction("将标签页移至新窗口");
    connect(addLabelToNewWindowAction,&QAction::triggered,[=](){
        qDebug()<<"将标签页移至新窗口";
    });
    labelPageMenu->addAction(addLabelToNewWindowAction);
    labelPageMenu->addSeparator();

}

void MainWindow::setupWindowMenu()
{
    QMenu *windowMenu = menuBar()->addMenu("窗口");

    QAction *minAction = new QAction("最小化",this);
    minAction->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_M));
    connect(minAction,&QAction::triggered,[=](){
        qDebug()<<"最小化";
    });
    windowMenu->addAction(minAction);

    QAction *scaleAction = new QAction("缩放",this);
    connect(scaleAction,&QAction::triggered,[=](){
        qDebug()<<"缩放";
    });
    windowMenu->addAction(scaleAction);

    QAction *moveToLeftAction = new QAction("将窗口拼贴到屏幕左侧",this);
    connect(moveToLeftAction,&QAction::triggered,[=](){
        qDebug()<<"将窗口拼贴到屏幕左侧";
    });
    windowMenu->addAction(moveToLeftAction);

    QAction *moveToRightAction = new QAction("将窗口拼贴到屏幕右侧",this);
    connect(moveToRightAction,&QAction::triggered,[=](){
        qDebug()<<"将窗口拼贴到屏幕右侧";
    });
    windowMenu->addAction(moveToRightAction);
    windowMenu->addSeparator();

    QAction *moveToAction = new QAction("移到\"S24E390\"",this);
    connect(moveToAction,&QAction::triggered,[=](){
        qDebug()<<"移到\"S24E390\"";
    });
    windowMenu->addAction(moveToAction);
    windowMenu->addSeparator();

    QAction *showToLabelAction = new QAction("显示为标签页",this);
    showToLabelAction->setEnabled(false);
    connect(showToLabelAction,&QAction::triggered,[=](){
        qDebug()<<"显示为标签页";
    });
    windowMenu->addAction(showToLabelAction);

    QAction *renameAction = new QAction("为窗口命名...",this);
    connect(renameAction,&QAction::triggered,[=](){
        qDebug()<<"为窗口命名...";
    });
    windowMenu->addAction(renameAction);
    windowMenu->addSeparator();

    QAction *downloadAction = new QAction("下载内容",this);
    downloadAction->setShortcut(QKeySequence(Qt::SHIFT|Qt::CTRL|Qt::Key_J));
    connect(downloadAction,&QAction::triggered,[=](){
        qDebug()<<"下载内容";
    });
    windowMenu->addAction(downloadAction);

    QAction *expandAction = new QAction("扩展程序",this);
    connect(expandAction,&QAction::triggered,[=](){
        qDebug()<<"扩展程序";
    });
    windowMenu->addAction(expandAction);

    QAction *taskAction = new QAction("任务管理器",this);
    connect(taskAction,&QAction::triggered,[=](){
        qDebug()<<"任务管理器";
    });
    windowMenu->addAction(taskAction);
    windowMenu->addSeparator();

    QAction *frontAction = new QAction("前置全部窗口",this);
    connect(frontAction,&QAction::triggered,[=](){
        qDebug()<<"前置全部窗口";
    });
    windowMenu->addAction(frontAction);
    windowMenu->addSeparator();
}

void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = menuBar()->addMenu("帮助");

//    SearchAction *searchAction = new SearchAction();
//    helpMenu->addAction(searchAction);

    QAction *reportAction = new QAction("报告问题...",this);
    reportAction->setShortcut(QKeySequence(Qt::CTRL|Qt::ALT|Qt::SHIFT|Qt::Key_I));
    connect(reportAction,&QAction::triggered,[=](){
        qDebug()<<"报告问题...";
    });
    helpMenu->addAction(reportAction);

    QAction *chromeHelpAction = new QAction("Google Chrome帮助",this);
    connect(chromeHelpAction,&QAction::triggered,[=](){
        qDebug()<<"Google Chrome帮助";
    });
    helpMenu->addAction(chromeHelpAction);
}

