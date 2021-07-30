#include "DownloadDialog.h"
#include "ui_DownloadDialog.h"

#include <QUrl>

DownloadDialog::DownloadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DownloadDialog)
{
    ui->setupUi(this);
    ui->urlLineEdit->setPlaceholderText("Enter the URL of an image to download");

    connect(ui->addUrlButton,&QPushButton::clicked,this,[=](){
        const auto text = ui->urlLineEdit->text();
        if (!text.isEmpty()) {
            ui->urlListWidget->addItem(text);
            ui->urlLineEdit->clear();
        }
    });

    connect(ui->urlListWidget,&QListWidget::itemSelectionChanged,[=](){
        ui->removeUrlButton->setEnabled(!ui->urlListWidget->selectedItems().empty());
    });
    connect(ui->clearUrlsButton,&QPushButton::clicked,ui->urlListWidget, &QListWidget::clear);
    connect(ui->removeUrlButton,&QPushButton::clicked,[=](){
        qDeleteAll(ui->urlListWidget->selectedItems());
    });

    connect(ui->buttonBox->button(QDialogButtonBox::Ok),&QPushButton::clicked,[=](){
        QList<QString> urls;
        for (auto row = 0; row < ui->urlListWidget->count();++row) {
            urls.push_back(ui->urlListWidget->item(row)->text());
        }
        emit getImageURLS(urls);
        this->hide();
    });

    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),&QPushButton::clicked,[=](){
        this->hide();
    });
}

DownloadDialog::~DownloadDialog()
{
    delete ui;
}

QList<QUrl> DownloadDialog::getUrls() const {
    QList<QUrl> urls;
    for (auto row = 0; row < ui->urlListWidget->count();++row) {
        urls.push_back(QUrl(ui->urlListWidget->item(row)->text()));
    }
    return urls;
}
