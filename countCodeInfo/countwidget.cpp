#include "countwidget.h"
#include "ui_countwidget.h"
#include <QVBoxLayout>
#include <qtablewidget.h>
#include <QHeaderView>
#include <qlineedit.h>

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
    gridLayout->addWidget(singleFileDirEdit,0,5,1,3);


}

CountWidget::~CountWidget()
{
    delete ui;
}
