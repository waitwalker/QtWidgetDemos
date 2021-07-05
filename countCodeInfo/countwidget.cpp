#include "countwidget.h"
#include "ui_countwidget.h"
#include <QVBoxLayout>
#include <qtablewidget.h>
#include <QHeaderView>

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
    vLayout->addWidget(tableWidget);


}

CountWidget::~CountWidget()
{
    delete ui;
}
