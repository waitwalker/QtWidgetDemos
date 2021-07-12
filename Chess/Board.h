#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
};

#endif // BOARD_H
