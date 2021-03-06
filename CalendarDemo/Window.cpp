#include "Window.h"
#include <QHBoxLayout>
#include <QWidget>
#include <locale>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("日历");

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);
    resize(800,600);
    //createPreviewGroupBox();
    createGeneralOptionsGroupBox();
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(calendar, 0, 0);
    layout->addWidget(generalOptionsGroupBox, 0, 1);
    setLayout(layout);
}

// 绘制右侧区域
void Window::createGeneralOptionsGroupBox() {
    generalOptionsGroupBox = new QGroupBox("General Options");

    // 初始化语言下拉框
    localeCombo = new QComboBox;
    // 当前语言索引
    int curLocaleIndex = -1;
    int index = 0;

    for (int _lang = QLocale::C; _lang < QLocale::LastLanguage ;++_lang ) {
        QLocale::Language lang = static_cast<QLocale::Language>(_lang);
        QList<QLocale::Country> countries = QLocale::countriesForLanguage(lang);
        for (int i = 0; i < countries.count() ; ++i ) {
            QLocale::Country country = countries.at(i);
            QString label = QLocale::languageToString(lang);
            label += QLatin1Char('/');
            label += QLocale::countryToString(country);
            QLocale locale(lang, country);
            if (this->locale().language() == lang && this->locale().country() == country) {
                curLocaleIndex = index;
            }
            localeCombo->addItem(label,locale);
            ++index;
        }
    }

    if (curLocaleIndex != -1) {
        localeCombo->setCurrentIndex(curLocaleIndex);
    }

    localeLabel = new QLabel("Locale");
    localeLabel->setBuddy(localeCombo);

    // 设置周末选项
    firstDayCombo = new QComboBox;
    firstDayCombo->addItem("Sunday",Qt::Sunday);
    firstDayCombo->addItem("Monday",Qt::Monday);
    firstDayCombo->addItem("Tuesday",Qt::Tuesday);
    firstDayCombo->addItem("Wednesday",Qt::Wednesday);
    firstDayCombo->addItem("Thursday",Qt::Thursday);
    firstDayCombo->addItem("Friday",Qt::Friday);
    firstDayCombo->addItem("Saturday",Qt::Saturday);

    firstDayLabel = new QLabel("Week starts on:");
    firstDayLabel->setBuddy(firstDayCombo);

    // 选择模式
    selectionModeCombo = new QComboBox;
    selectionModeCombo->addItem("Single selection",QCalendarWidget::SingleSelection);
    selectionModeCombo->addItem("None",QCalendarWidget::NoSelection);

    selectionModeLabel = new QLabel("Selection Mode:");
    selectionModeLabel->setBuddy(selectionModeCombo);

    // 单选框
    gridCheckBox = new QCheckBox("Grid");
    gridCheckBox->setChecked(true);

    navigationCheckBox = new QCheckBox("Navigation Bar");
    navigationCheckBox->setChecked(true);

    // 横向
    horizontalHeaderCombo = new QComboBox;
    horizontalHeaderCombo->addItem("Single letter day names",QCalendarWidget::SingleLetterDayNames);
    horizontalHeaderCombo->addItem("Short day names",QCalendarWidget::ShortDayNames);
    horizontalHeaderCombo->addItem("None",QCalendarWidget::NoHorizontalHeader);
    horizontalHeaderCombo->setCurrentIndex(1);

    horizontalHeaderLabel = new QLabel("Horizontal header");
    horizontalHeaderLabel->setBuddy(horizontalHeaderCombo);

    // 纵向
    verticalHeaderCombo = new QComboBox;
    verticalHeaderCombo->addItem("ISO week numbers",QCalendarWidget::ISOWeekNumbers);
    verticalHeaderCombo->addItem("None",QCalendarWidget::NoVerticalHeader);

    verticalHeaderLabel = new QLabel("Vertical header");
    verticalHeaderLabel->setBuddy(verticalHeaderCombo);

    QHBoxLayout *checkBoxLayout = new QHBoxLayout;
    checkBoxLayout->addWidget(gridCheckBox);
    checkBoxLayout->addStretch();
    checkBoxLayout->addWidget(navigationCheckBox);

    QGridLayout *outerLayout = new QGridLayout;
    outerLayout->addWidget(localeLabel, 0,0);
    outerLayout->addWidget(localeCombo,0,1);
    outerLayout->addWidget(firstDayLabel,1,0);
    outerLayout->addWidget(firstDayCombo,1,1);
    outerLayout->addWidget(selectionModeLabel,2,0);
    outerLayout->addWidget(selectionModeCombo,2,1);
    outerLayout->addLayout(checkBoxLayout,3,0,1,2);
    outerLayout->addWidget(horizontalHeaderLabel,4,0);
    outerLayout->addWidget(horizontalHeaderCombo,4,1);
    outerLayout->addWidget(verticalHeaderLabel,5,0);
    outerLayout->addWidget(verticalHeaderCombo,5,1);
    generalOptionsGroupBox->setLayout(outerLayout);

    // 下拉框点击回调事件
    connect(localeCombo,&QComboBox::currentIndexChanged,[=](int currentIndex){
        const QLocale newLocale(localeCombo->itemData(currentIndex).toLocale());
        qDebug()<<"国际化语言:"<<newLocale;
        calendar->setLocale(newLocale);

        int newLocaleFirstDayIndex = firstDayCombo->findData(newLocale.firstDayOfWeek());
        firstDayCombo->setCurrentIndex(newLocaleFirstDayIndex);
    });

    connect(firstDayCombo,&QComboBox::currentIndexChanged,[=](int currentIndex){
        qDebug()<<"星期:"<<firstDayCombo->itemData(currentIndex).toInt();
        calendar->setFirstDayOfWeek(Qt::DayOfWeek(firstDayCombo->itemData(currentIndex).toInt()));
    });

    connect(selectionModeCombo,&QComboBox::currentIndexChanged,[=](int currentIndex){
        qDebug()<<"选择模式:"<<selectionModeCombo->itemData(currentIndex).toInt();
        calendar->setSelectionMode(QCalendarWidget::SelectionMode(selectionModeCombo->itemData(currentIndex).toInt()));
    });

    connect(gridCheckBox,&QCheckBox::toggled,[=](bool checked){
        qDebug()<<"gridCheckBox是否选中:"<<checked;
    });

    connect(navigationCheckBox,&QCheckBox::toggled,[=](bool checked){
        qDebug()<<"navigationCheckBox是否选中:"<<checked;
    });

    connect(horizontalHeaderCombo,&QComboBox::currentIndexChanged,[=](int currentIndex){
        qDebug()<<"horizontalHeaderCombo:"<<horizontalHeaderCombo->itemData(currentIndex).toInt();
        calendar->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat(horizontalHeaderCombo->itemData(currentIndex).toInt()));
    });

    connect(verticalHeaderCombo,&QComboBox::currentIndexChanged,[=](int currentIndex){
        qDebug()<<"verticalHeaderCombo:"<<verticalHeaderCombo->itemData(currentIndex).toInt();
        calendar->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat(verticalHeaderCombo->itemData(index).toInt()));
    });


}

void Window::createPreviewGroupBox() {
    previewGroupBox = new QGroupBox("Preview");
    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);

    previewLayout = new QGridLayout;
    previewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    previewGroupBox->setLayout(previewLayout);
}

Window::~Window()
{

}
