#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkReply>
#include <QPromise>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Image downloading and scaling example"));
    resize(800,600);

    addUrlsButton = new QPushButton(tr("Add URLs"));

    downloadDialog = new DownloadDialog();

    connect(downloadDialog,&DownloadDialog::getImageURLS,[=](QList<QString> &urlStrings){
        replies.clear();
        if (urlStrings.isEmpty()) {
            return ;
        }

        qDebug()<<urlStrings;

        QList<QUrl> urls;
        for (auto urlString:urlStrings ) {
            urls.push_back(QUrl(urlString));
        }

        cancelButton->setEnabled(true);
        initLayout(urls.size());

        downloadFuture = download(urls);
        statusBar->showMessage("正在下载...");

        downloadFuture
                .then([this](auto) { cancelButton->setEnabled(false); })
                .then(QtFuture::Launch::Async,[this]{QMetaObject::invokeMethod(this,[this] { updateStatus(tr("Scaling...")); });
                          return scaled();})
                .then(this, [this](const QList<QImage> &scaled) {
                    showImages(scaled);
                    updateStatus(tr("Finished"));
                })
                .onCanceled([this] { updateStatus(tr("Download has been canceled.")); })
                .onFailed([this](QNetworkReply::NetworkError error) {
                    updateStatus(tr("Download finished with error: %1").arg(error));

                    // Abort all pending requests
                    abortDownload();
                })
                .onFailed([this](const std::exception& ex) {
                    updateStatus(tr(ex.what()));
                });
    });

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
        downloadDialog->show();
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
    QSharedPointer<QPromise<QByteArray>> promise(new QPromise<QByteArray>());
    promise->start();

    for(auto url: urls) {
        QSharedPointer<QNetworkReply> reply(qnam.get(QNetworkRequest(url)));
        replies.push_back(reply);

        QtFuture::connect(reply.get(),&QNetworkReply::finished).then([=]{
            if (promise->isCanceled()) {
                if (!promise->future().isFinished()) {
                    promise->finish();
                }
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                if (!promise->future().isFinished()) {
                    throw reply->error();
                }
            }

            promise->addResult(reply->readAll());

            if (promise->future().resultCount() == urls.size()) {
                promise->finish();
            }
        }).onFailed([=] (QNetworkReply::NetworkError error){
            promise->setException(std::make_exception_ptr(error));
            promise->finish();
        }).onFailed([=]{
            const auto ex = std::make_exception_ptr(std::runtime_error("Unknown error"));
            promise->setException(ex);
            promise->finish();
        });
    }
    return promise->future();
}

QList<QImage> MainWindow::scaled() const
{
    QList<QImage> scaled;
    const auto data = downloadFuture.results();
    for (auto imgData : data ) {
        QImage image;
        image.loadFromData(imgData);
        if (image.isNull()) {
            throw std::runtime_error("Failed to load image.");
        }
        scaled.push_back(image.scaled(100,120,Qt::KeepAspectRatio));
    }
    return scaled;
}

void MainWindow::updateStatus(const QString &msg)
{
    statusBar->showMessage(msg);
}

void MainWindow::showImages(const QList<QImage> &images)
{
    for (int i = 0; i < images.size() ; ++i ) {
        labels[i]->setAlignment(Qt::AlignCenter);
        labels[i]->setPixmap(QPixmap::fromImage(images[i]));
    }
}

void MainWindow::abortDownload()
{
    for (auto reply: replies ) {
        reply->abort();
    }

}

