#include "mainwindow.h"

#include <QApplication>
#include <Board.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Board board;
    board.show();

    return a.exec();
}
