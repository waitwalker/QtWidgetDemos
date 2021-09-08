#include "MainPage.h"
#include "ui_MainPage.h"
#include <QLabel>
#include <QVBoxLayout>

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("主页");
    this->resize(800,600);

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setSpacing(0);
    vBoxLayout->setContentsMargins(0,0,0,0);

    QLabel *label1 = new QLabel("新建");
    label1->setStyleSheet("background-color:#FF8080");
    label1->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    label1->setMinimumWidth(150);
    vBoxLayout->addWidget(label1);


    QLabel *label2 = new QLabel("打开");
    label2->setStyleSheet("background-color:#FF2520");
    label2->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    vBoxLayout->addWidget(label2);
    vBoxLayout->addStretch();


}

MainPage::~MainPage()
{
    delete ui;
}
