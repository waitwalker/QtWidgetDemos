#include "mainwindow.h"

#include <QApplication>
#include "HomeWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeWindow homeWindow;
    homeWindow.show();
    return a.exec();
}
