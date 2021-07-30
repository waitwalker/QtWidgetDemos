#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Image downloading and scaling example"));
    resize(800,600);

    addUrlsButton = new QPushButton(tr("Add URLs"));


    cancelButton = new QPushButton("Cancel");
    cancelButton->setEnabled(false);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addUrlsButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addStretch();

    statusBar = new QStatusBar();

    imagesLayout = new QGridLayout();

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(imagesLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(statusBar);

    QWidget *mainWidget = new QWidget(this);
    //mainWidget->setStyleSheet("background-color:white");
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

    connect(addUrlsButton,&QPushButton::clicked,[=](){

    });

    connect(cancelButton,&QPushButton::clicked,[=](){
        this->statusBar->showMessage("Canceling");
        downloadFuture.cancel();
        abortDownload();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLayout(qsizetype count)
{
    QLayoutItem *child;
    while ((child = imagesLayout->takeAt(0)) != nullptr) {
        child->widget()->setParent(nullptr);
    }
    labels.clear();

    const auto dim = int(qSqrt(qreal(count))) + 1;
    for (int i = 0; i < dim; i++ ) {
        for (int j = 0; j < dim; j++ ) {
            QLabel *imageLabel = new QLabel;
            imageLabel->setFixedSize(100,120);
            imagesLayout->addWidget(imageLabel,i,j);
            labels.append(imageLabel);
        }
    }
}

QFuture<QByteArray> MainWindow::download(const QList<QUrl> &urls)
{

}

QList<QImage> MainWindow::scaled() const
{

}

void MainWindow::updateStatus(const QString &msg)
{
    statusBar->showMessage(msg);
}

void MainWindow::showImages(const QList<QImage> &images)
{

}

void MainWindow::abortDownload()
{
    for (auto reply: replies ) {
        reply->abort();
    }

}

