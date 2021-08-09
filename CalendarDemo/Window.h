#ifndef WINDOW_H
#define WINDOW_H

#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QWindow>
#include <QWidget>



class Window: public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();

public:
    enum SelectionMode{
        NoSelection,
        SingleSelection
    };
    Q_ENUM(SelectionMode);
private:

    QGroupBox *generalOptionsGroupBox;

    QComboBox *localeCombo;
    QLabel *localeLabel;

    QComboBox *firstDayCombo;
    QLabel *firstDayLabel;

    QComboBox *selectionModeCombo;
    QLabel *selectionModeLabel;

    QCheckBox *gridCheckBox;
    QCheckBox *navigationCheckBox;

    QComboBox *horizontalHeaderCombo;
    QLabel *horizontalHeaderLabel;

    QComboBox *verticalHeaderCombo;
    QLabel *verticalHeaderLabel;






private:
    void createGeneralOptionsGroupBox();
};

#endif // WINDOW_H
