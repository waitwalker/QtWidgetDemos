#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include "base64tool.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1)创建一个widget
    QWidget *widget = new QWidget;

    // 总容器 垂直
    QVBoxLayout *vLayout = new QVBoxLayout(widget);

    // 上部容器 水平
    QHBoxLayout *topHLayout = new QHBoxLayout;
    // 输入框容器 水平
    QHBoxLayout *lineContainer = new QHBoxLayout;
    // 按钮容器 水平
    QHBoxLayout *buttonContainer = new QHBoxLayout;

    // 输入框
    QLineEdit *lineEdit = new QLineEdit;
    QPushButton *openFile = new QPushButton("打开文件");
    openFile->setStyleSheet(
                //正常状态样式
                "QPushButton{"
                "background-color:rgba(100,225,100,100);"//背景色（也可以设置图片）
                "border-style:outset;"                  //边框样式（inset/outset）
                "border-width:1px;"                     //边框宽度像素
                "border-radius:10px;"                   //边框圆角半径像素
                "border-color:rgba(255,255,255,00);"    //边框颜色
                "font:bold 15px;"                       //字体，字体大小
                "color:rgba(0,0,0,100);"                //字体颜色
                "padding:1px;"                          //填衬
                "}"
                //鼠标按下样式
                "QPushButton:pressed{"
                "background-color:rgba(100,255,100,200);"
                "border-color:rgba(255,255,255,30);"
                "border-style:inset;"
                "color:rgba(0,0,0,000);"
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:rgba(100,255,100,100);"
                "border-color:rgba(255,255,255,000);"
                "color:rgba(0,0,0,200);"
                "}");
    QPushButton *imageToBase64 = new QPushButton("图片转base64");
    QPushButton *base64ToImage = new QPushButton("base64转图片");
    lineContainer->addWidget(lineEdit);

    buttonContainer->addWidget(openFile);
    buttonContainer->addWidget(imageToBase64);
    buttonContainer->addWidget(base64ToImage);

    topHLayout->addLayout(lineContainer);
    topHLayout->addLayout(buttonContainer);
    topHLayout->setSpacing(10);
    topHLayout->setStretchFactor(lineContainer,1);
    topHLayout->setStretchFactor(buttonContainer,1);

    // 中部容器 水平
    QHBoxLayout *middleHLayout = new QHBoxLayout;
    // 输入框容器 水平
    QHBoxLayout *lineContainer2 = new QHBoxLayout;
    // 按钮容器 水平
    QHBoxLayout *buttonContainer2 = new QHBoxLayout;

    // 输入框
    QLineEdit *lineEdit2 = new QLineEdit;
    QPushButton *clearDataButton = new QPushButton("清空数据");
    clearDataButton->setStyleSheet(
                //正常状态样式
                "QPushButton{"
                "background-color:rgba(100,225,100,100);"//背景色（也可以设置图片）
                "border-style:outset;"                  //边框样式（inset/outset）
                "border-width:1px;"                     //边框宽度像素
                "border-radius:10px;"                   //边框圆角半径像素
                "border-color:rgba(255,255,255,00);"    //边框颜色
                "font:bold 15px;"                       //字体，字体大小
                "color:rgba(0,0,0,100);"                //字体颜色
                "padding:1px;"                          //填衬
                "}"
                //鼠标按下样式
                "QPushButton:pressed{"
                "background-color:rgba(100,255,100,200);"
                "border-color:rgba(255,255,255,30);"
                "border-style:inset;"
                "color:rgba(0,0,0,000);"
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:rgba(100,255,100,100);"
                "border-color:rgba(255,255,255,000);"
                "color:rgba(0,0,0,200);"
                "}");
    QPushButton *textToBase64 = new QPushButton("文字转base64");
    QPushButton *base64ToText = new QPushButton("base64转文字");
    lineContainer2->addWidget(lineEdit2);

    buttonContainer2->addWidget(clearDataButton);
    buttonContainer2->addWidget(textToBase64);
    buttonContainer2->addWidget(base64ToText);

    middleHLayout->addLayout(lineContainer2);
    middleHLayout->addLayout(buttonContainer2);
    middleHLayout->setSpacing(10);
    middleHLayout->setStretchFactor(lineContainer2,1);
    middleHLayout->setStretchFactor(buttonContainer2,1);

    QLabel *imageLabel = new QLabel;
    imageLabel->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");

    QLabel *textLabel = new QLabel;
    textLabel->setStyleSheet("QLabel{border:2px solid rgb(255, 255, 0);}");



    //void QLayout::setContentsMargins(int left, int top, int right, int bottom)
    vLayout->setContentsMargins(30,20,30,0);

    // 设置控件之间的间距
    //vLayout->setSpacing(10);
    // 居中显示 上下分别添加一个弹簧
    // 居下显示 在上面添加一个弹簧
    //vLayout->addStretch();
    vLayout->addLayout(topHLayout);
    vLayout->addLayout(middleHLayout);
    vLayout->addWidget(imageLabel);
    vLayout->addWidget(textLabel);
    vLayout->setSpacing(10);
    //  居上显示 添加一个弹框
    vLayout->addStretch();
    vLayout->setAlignment(Qt::AlignTop);
    vLayout->setStretchFactor(imageLabel,5);
    vLayout->setStretchFactor(textLabel,5);

    widget->setLayout(vLayout);
    setCentralWidget(widget);

    connect(openFile,&QPushButton::clicked,[=](){
        QString filePath = QFileDialog::getOpenFileName(this,"选择文件","","图片(*.png *.jpg *.PNG *JPG *.jpeg *.JPEG *.heic *HEIC)");
        qDebug()<<filePath;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

