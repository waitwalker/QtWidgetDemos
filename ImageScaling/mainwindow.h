#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DownloadDialog.h"

#include <QFuture>
#include <QLabel>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 初始化布局
    void initLayout(qsizetype count);

    // 下载
    QFuture<QByteArray> download(const QList<QUrl> &urls);

    QList<QImage> scaled() const;

    void updateStatus(const QString &msg);
    void showImages(const QList<QImage> &images);
    void abortDownload();

private:
    Ui::MainWindow *ui;

    QPushButton *addUrlsButton;
    QPushButton *cancelButton;
    QVBoxLayout *mainLayout;
    QList<QLabel *> labels;
    QGridLayout *imagesLayout;
    QStatusBar *statusBar;
    DownloadDialog *downloadDialog;

    QNetworkAccessManager qnam;
    QList<QSharedPointer<QNetworkReply>> replies;
    QFuture<QByteArray> downloadFuture;

};
#endif // MAINWINDOW_H
