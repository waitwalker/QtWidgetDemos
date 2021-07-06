#include "countwidget.h"
#include "ui_countwidget.h"
#include <QVBoxLayout>
#include <qtablewidget.h>
#include <QHeaderView>
#include <qlineedit.h>
#include <qpushbutton.h>

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


}

CountWidget::~CountWidget()
{
    delete ui;
}
