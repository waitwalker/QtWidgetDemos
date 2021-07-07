#include "countwidget.h"
#include "ui_countwidget.h"
#include <QVBoxLayout>
#include <qtablewidget.h>
#include <QHeaderView>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QFileDialog>
#include <QtGlobal>

CountWidget::CountWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountWidget)
{
    ui->setupUi(this);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    this->setLayout(vLayout);

    QStringList headText;
    headText<<"文件名"<<"类型"<<"大小"<<"总行数"<<"代码行数"<<"注释函数"<<"空白行数"<<"路径";
    QList<int> columnWidth;
    columnWidth<<130<<50<<70<<80<<70<<70<<70<<150;


    int columnCount = headText.count();
    QTableWidget *tableWidget = new QTableWidget();
    tableWidget->setColumnCount(columnCount);
    tableWidget->setHorizontalHeaderLabels(headText);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setDefaultSectionSize(20);
    tableWidget->verticalHeader()->setHighlightSections(false);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setHighlightSections(false);

    for (int i = 0; i < columnCount ; i++ ) {
        tableWidget->setColumnWidth(i, columnWidth[i]);
    }
    vLayout->addWidget(tableWidget,3);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setColumnMinimumWidth(0, 50);
    gridLayout->setColumnMinimumWidth(1, 100);
    gridLayout->setColumnMinimumWidth(2, 80);
    gridLayout->setColumnMinimumWidth(3, 100);
    gridLayout->setColumnMinimumWidth(4, 100);
    vLayout->addLayout(gridLayout,1);

    QLabel *fileNumLabel = new QLabel();
    fileNumLabel->setText("文件数");
    gridLayout->addWidget(fileNumLabel,0,0,1,1);

    QLineEdit *fileNumEdit = new QLineEdit();
    gridLayout->addWidget(fileNumEdit,0,1,1,1);

    QLabel *codeNumLabel = new QLabel();
    codeNumLabel->setText("代码行数");
    gridLayout->addWidget(codeNumLabel,0,2,1,1);

    QLineEdit *codeNumEdit = new QLineEdit();
    codeNumEdit->setText("0%");
    gridLayout->addWidget(codeNumEdit,0,3,1,1);

    QLabel *singleFileDirLabel = new QLabel();
    singleFileDirLabel->setText("单个文件目录");
    gridLayout->addWidget(singleFileDirLabel,0,4,1,1);

    QLineEdit *singleFileDirEdit = new QLineEdit();
    gridLayout->addWidget(singleFileDirEdit,0,5,1,1);

    QPushButton *openSingleFileButton = new QPushButton("打开文件");
    gridLayout->addWidget(openSingleFileButton,0,6,1,1);

    QLabel *byteNumLabel = new QLabel();
    byteNumLabel->setText("字节数");
    gridLayout->addWidget(byteNumLabel,1,0,1,1);

    QLineEdit *byteNumEdit = new QLineEdit();
    gridLayout->addWidget(byteNumEdit,1,1,1,1);

    QLabel *noteCodeNumLabel = new QLabel();
    noteCodeNumLabel->setText("注释行数");
    gridLayout->addWidget(noteCodeNumLabel,1,2,1,1);

    QLineEdit *noteCodeNumEdit = new QLineEdit();
    noteCodeNumEdit->setText("0%");
    gridLayout->addWidget(noteCodeNumEdit,1,3,1,1);

    QLabel *allFileDirLabel = new QLabel();
    allFileDirLabel->setText("全部文件目录");
    gridLayout->addWidget(allFileDirLabel,1,4,1,1);

    QLineEdit *allFileDirEdit = new QLineEdit();
    gridLayout->addWidget(allFileDirEdit,1,5,1,1);

    QPushButton *openAllFileButton = new QPushButton("打开目录");
    gridLayout->addWidget(openAllFileButton,1,6,1,1);

    QLabel *lineNumLabel = new QLabel();
    lineNumLabel->setText("总行数");
    gridLayout->addWidget(lineNumLabel,2,0,1,1);

    QLineEdit *lineNumEdit = new QLineEdit();
    gridLayout->addWidget(lineNumEdit,2,1,1,1);

    QLabel *blankLineNumLabel = new QLabel();
    blankLineNumLabel->setText("空白行数");
    gridLayout->addWidget(blankLineNumLabel,2,2,1,1);

    QLineEdit *blankNumEdit = new QLineEdit();
    blankNumEdit->setText("0%");
    gridLayout->addWidget(blankNumEdit,2,3,1,1);

    QLabel *filtLabel = new QLabel();
    filtLabel->setText("过滤");
    gridLayout->addWidget(filtLabel,2,4,1,1);

    QLineEdit *filtEdit = new QLineEdit();
    filtEdit->setText("*.h *.cpp *.cs *.java *.js");
    gridLayout->addWidget(filtEdit,2,5,1,1);

    QPushButton *clearButton = new QPushButton("清空结果");
    gridLayout->addWidget(clearButton,2,6,1,1);

    this->tableWidget = tableWidget;
    this->fileNumLabel = fileNumLabel;
    this->fileNumEdit = fileNumEdit;
    this->codeNumLabel = codeNumLabel;
    this->codeNumEdit = codeNumEdit;
    this->singleFileDirLabel = singleFileDirLabel;
    this->singleFileDirEdit = singleFileDirEdit;
    this->openSingleFileButton = openSingleFileButton;

    this->byteNumLabel = byteNumLabel;
    this->byteNumEdit = byteNumEdit;
    this->noteNumLabel = noteCodeNumLabel;
    this->noteNumEdit = noteCodeNumEdit;
    this->allFileDirLabel = allFileDirLabel;
    this->allFileDirEdit = allFileDirEdit;
    this->openAllDirButton = openAllFileButton;

    this->allLineNumLabel = lineNumLabel;
    this->allLineNumEdit = lineNumEdit;
    this->blankNumLabel = blankLineNumLabel;
    this->blankNumEdit = blankNumEdit;
    this->filterLabel = filtLabel;
    this->filterEdit = filtEdit;
    this->clearButton = clearButton;

    connect(this->openSingleFileButton,&QPushButton::clicked,[=](){
        QString filter = QString("代码文件(%1)").arg(filtEdit->text());
        QStringList files = QFileDialog::getOpenFileNames(this,"选择文件", "./", filter);
        if (files.size() > 0) {

            countCode(files);
            this->singleFileDirEdit->setText(files.join("1"));
        }
    });

    connect(this->openAllDirButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getExistingDirectory(this,"选择目录", "./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        if (!path.isEmpty()) {
            listFile.clear();
            countCode(path);
            countCode(listFile);
            this->allFileDirEdit->setText(path);
        }
    });

    connect(this->clearButton,&QPushButton::clicked,[=](){
        this->fileNumEdit->setText("0");
        this->codeNumEdit->setText("0%");
        this->singleFileDirEdit->clear();

        this->byteNumEdit->setText("0");
        this->noteNumEdit->setText("0%");
        this->allFileDirEdit->clear();

        this->allLineNumEdit->setText("0");
        this->blankNumEdit->setText("0%");
        this->tableWidget->setRowCount(0);
    });

}

CountWidget::~CountWidget()
{
    delete ui;
}

bool CountWidget::checkFile(const QString &fileName)
{
    if (fileName.startsWith("moc_") || fileName.startsWith("ui_") || fileName.startsWith("qrc_")) {
        return false;
    }
    QFileInfo fileInfo(fileName);
    QString suffix = "*." + fileInfo.suffix();
    QString filter = this->filterEdit->text().trimmed();
    QStringList filters = filter.split(" ");
    return filters.contains(suffix);
}

void CountWidget::countCode(const QString &filePath)
{
    QDir dir(filePath);
    QFileInfoList fileInfos = dir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfos) {
        QString fileName = fileInfo.fileName();
        if (fileInfo.isFile()) {
            if (checkFile(fileName)) {
                listFile<<fileInfo.filePath();
            }
        } else {
            if (fileName == "." || fileName == "..") {
                continue;
            }
            // 递归查找文件
            countCode(fileInfo.absoluteFilePath());
        }
    }
}

void CountWidget::countCode(const QStringList &files)
{
    int lineCode;
    int lineBlank;
    int linetNote;
    int count = files.count();
    this->clearButton->click();
    this->tableWidget->setRowCount(count);

    quint32 totalLines = 0;
    quint32 totalBytes = 0;
    quint32 totalCodes = 0;
    quint32 totalNote = 0;
    quint32 totalBlank = 0;

    for (int i = 0; i < count; i++) {
        QFileInfo fileInfo(files[i]);
        countCode(fileInfo.filePath(), lineCode, lineBlank, linetNote);
        int lineAll = lineCode + lineBlank + linetNote;
        QTableWidgetItem *itemName = new QTableWidgetItem;
        itemName->setText(fileInfo.fileName());

        QTableWidgetItem *itemSuffex = new QTableWidgetItem;
        itemSuffex->setText(fileInfo.suffix());

        QTableWidgetItem *itemSize = new QTableWidgetItem;
        itemSize->setText(QString::number(fileInfo.size()));

        QTableWidgetItem *itemLine = new QTableWidgetItem;
        itemLine->setText(QString::number(lineAll));

        QTableWidgetItem *itemCode = new QTableWidgetItem;
        itemCode->setText(QString::number(lineCode));

        QTableWidgetItem *itemNote = new QTableWidgetItem;
        itemNote->setText(QString::number(linetNote));

        QTableWidgetItem *itemBlank = new QTableWidgetItem;
        itemBlank->setText(QString::number(lineBlank));

        QTableWidgetItem *itemPath = new QTableWidgetItem;
        itemPath->setText(fileInfo.filePath());

        itemSuffex->setTextAlignment(Qt::AlignCenter);
        itemSize->setTextAlignment(Qt::AlignCenter);
        itemLine->setTextAlignment(Qt::AlignCenter);
        itemCode->setTextAlignment(Qt::AlignCenter);
        itemNote->setTextAlignment(Qt::AlignCenter);
        itemBlank->setTextAlignment(Qt::AlignCenter);

        this->tableWidget->setItem(i, 0, itemName);
        this->tableWidget->setItem(i, 1, itemSuffex);
        this->tableWidget->setItem(i, 2, itemSize);
        this->tableWidget->setItem(i, 3, itemLine);
        this->tableWidget->setItem(i, 4, itemCode);
        this->tableWidget->setItem(i, 5, itemNote);
        this->tableWidget->setItem(i, 6, itemBlank);
        this->tableWidget->setItem(i, 7, itemPath);

        totalBytes +=fileInfo.size();
        totalLines += lineAll;
        totalCodes += lineCode;
        totalNote += linetNote;
        totalBlank += lineBlank;

        if (i % 100 == 0) {
            qApp->processEvents();
        }

        // 显示统计结果
        listFile.clear();
        this->fileNumEdit->setText(QString::number(count));
        this->byteNumEdit->setText(QString::number(totalBytes));
        this->allLineNumEdit->setText(QString::number(totalLines));

        this->codeNumEdit->setText(QString::number(totalLines));
        this->noteNumEdit->setText(QString::number(totalNote));
        this->blankNumEdit->setText(QString::number(totalBlank));
    }
}

void CountWidget::countCode(const QString &fileName, int &lineCode, int &lineBlank, int &lineNote)
{
    lineCode = lineBlank = lineNote = 0;
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QTextStream out(&file);
        QString line;
        bool isNote = false;
        while (!out.atEnd()) {
            // 一行一行读
            line = out.readLine();
            // 移除前面的空行
            if(line.startsWith(" ")) {
                line.remove(" ");
            }

            // 判断当前行是否是注释
            if (line.startsWith("/")) {
                isNote = true;
            }

            // 注释部分
            if (isNote) {
                lineNote++;
            } else {
                if (line.startsWith("//")) {
                    lineNote++;
                } else if (line.isEmpty()) {
                    lineBlank++;
                } else {
                    lineCode++;
                }
            }

            // 注释结束
            if (line.endsWith("*/")) {
                isNote = false;
            }
        }
    }
}
