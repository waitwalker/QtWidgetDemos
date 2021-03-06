#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    void initMenu();

    void setupFirstHelpMenu();
    void setupFileMenu();
    void setupEditMenu();
    void setupViewMenu();
    void setupHistoryMenu();
    void setupBookmarkMenu();
    void setupPersonDataMenu();
    void setupLabelPageMenu();
    void setupWindowMenu();
    void setupHelpMenu();

};
#endif // MAINWINDOW_H
