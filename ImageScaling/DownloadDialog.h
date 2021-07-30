#ifndef DOWNLOADDIALOG_H
#define DOWNLOADDIALOG_H

#include <QDialog>

namespace Ui {
class DownloadDialog;
}

class DownloadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DownloadDialog(QWidget *parent = nullptr);
    ~DownloadDialog();

    QList<QUrl> getUrls() const;

signals:
    void getImageURLS(QList<QString> &imageUrls);

private:
    Ui::DownloadDialog *ui;
};

#endif // DOWNLOADDIALOG_H
