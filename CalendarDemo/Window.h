#ifndef WINDOW_H
#define WINDOW_H

#include <QWindow>



class Window: public QWindow
{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();
};

#endif // WINDOW_H
