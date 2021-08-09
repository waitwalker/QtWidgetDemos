#include "Window.h"

#include <QCalendarWidget>
#include <QWidget>
#include <locale>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("日历");
    resize(800,600);
    createGeneralOptionsGroupBox();
}

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

}

Window::~Window()
{

}
