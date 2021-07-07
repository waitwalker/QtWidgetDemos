#ifndef COUNTWIDGET_H
#define COUNTWIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QTableWidget>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class CountWidget;
}

class CountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CountWidget(QWidget *parent = nullptr);
    ~CountWidget();

private:
    Ui::CountWidget *ui;

    QTableWidget *tableWidget;
    QGridLayout *gridLayout;

    QLabel *fileNumLabel;
    QLineEdit *fileNumEdit;

    QLabel *codeNumLabel;
    QLineEdit *codeNumEdit;

    QLabel *singleFileDirLabel;
    QLineEdit *singleFileDirEdit;

    QPushButton *openSingleFileButton;

    QLabel *byteNumLabel;
    QLineEdit *byteNumEdit;

    QLabel *noteNumLabel;
    QLineEdit *noteNumEdit;

    QLabel *allFileDirLabel;
    QLineEdit *allFileDirEdit;

    QPushButton *openAllDirButton;

    QLabel *allLineNumLabel;
    QLineEdit *allLineNumEdit;

    QLabel *blankNumLabel;
    QLineEdit *blankNumEdit;

    QLabel *filterLabel;
    QLineEdit *filterEdit;

    QPushButton *clearButton;

    QStringList listFile;

    bool checkFile(const QString &fileName);
    void countCode(const QString &filePath);
    void countCode(const QStringList &files);
    void countCode(const QString &fileName, int &lineCode, int &lineBlank, int &lineNote);


};

#endif // COUNTWIDGET_H
