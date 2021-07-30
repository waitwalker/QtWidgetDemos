#include "DownloadDialog.h"
#include "ui_DownloadDialog.h"

DownloadDialog::DownloadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DownloadDialog)
{
    ui->setupUi(this);

}

DownloadDialog::~DownloadDialog()
{
    delete ui;
}

QList<QUrl> DownloadDialog::getUrls() const {
    QList<QUrl> urls;
    for (auto row = 0; row < ui->urlListWidget.count;++row) {

    }
}
