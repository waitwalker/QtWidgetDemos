#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QDialogButtonBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWidget *containerWidget = new QWidget(this);
    this->setCentralWidget(containerWidget);

    QVBoxLayout *verticalLayout = new QVBoxLayout(containerWidget);


    // 按钮容器
    QGroupBox *buttonsGroup = new QGroupBox("按钮容器");
    QHBoxLayout *buttonContainer = new QHBoxLayout;
    QPushButton *button1 = new QPushButton("button1");
    QPushButton *button2 = new QPushButton("button2");
    QPushButton *button3 = new QPushButton("button3");
    QPushButton *button4 = new QPushButton("button4");
    QPushButton *button5 = new QPushButton("button5");
    buttonContainer->addWidget(button1);
    buttonContainer->addWidget(button2);
    buttonContainer->addWidget(button3);
    buttonContainer->addWidget(button4);
    buttonContainer->addWidget(button5);
    buttonsGroup->setLayout(buttonContainer);

    verticalLayout->addWidget(buttonsGroup);

    // Grid容器
    QGroupBox *gridGroup = new QGroupBox("Grid");
    QGridLayout *gridLayout = new QGridLayout;

    QLabel *label1 = new QLabel("Line 1");
    QLineEdit *lineEdit1 = new QLineEdit;
    QLabel *label2 = new QLabel("Line 2");
    QLineEdit *lineEdit2 = new QLineEdit;
    QLabel *label3 = new QLabel("Line 3");
    QLineEdit *lineEdit3 = new QLineEdit;

    gridLayout->addWidget(label1,0,0);
    gridLayout->addWidget(lineEdit1,0,1);

    gridLayout->addWidget(label2,1,0);
    gridLayout->addWidget(lineEdit2,1,1);

    gridLayout->addWidget(label3,2,0);
    gridLayout->addWidget(lineEdit3,2,1);

    QTextEdit *textEdit =  new QTextEdit;
    textEdit->setPlainText("文本输入框");
    // 从第一行,第3列(0,1,2)开始,占4行1列
    gridLayout->addWidget(textEdit,0,2,4,1);

    // 设置当前列所占
    gridLayout->setColumnStretch(2,5);
    gridGroup->setLayout(gridLayout);
    verticalLayout->addWidget(gridGroup);


    QGroupBox *formGroup = new QGroupBox("Form");
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(new QLabel("Line 1", new QLineEdit));
    formLayout->addRow(new QLabel("Line 2", new QComboBox));
    formLayout->addRow(new QLabel("Line 3", new QSpinBox));
    formLayout->addWidget(new QLineEdit);

    formGroup->setLayout(formLayout);
    verticalLayout->addWidget(formGroup);

    QTextEdit *bottomEdit = new QTextEdit;
    bottomEdit->setPlainText("Bottom edit");
    verticalLayout->addWidget(bottomEdit);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);
    connect(buttonBox,&QDialogButtonBox::accepted,[=](){
        qDebug()<<"OK clicked";
    });
    connect(buttonBox,&QDialogButtonBox::rejected,[=](){
        qDebug()<<"Close clicked";
        this->hide();
    });
    verticalLayout->addWidget(buttonBox);
    verticalLayout->addStretch();
}

MainWindow::~MainWindow()
{
    delete ui;
}

