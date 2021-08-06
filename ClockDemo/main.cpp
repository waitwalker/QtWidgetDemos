#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include "RasterWindow.h"

class AnalogClockWindow: public RasterWindow {
public:
    AnalogClockWindow();
protected:
    void timerEvent(QTimerEvent *) override;
    void render(QPainter *p) override;
private:
    int m_timerId;
};

AnalogClockWindow::AnalogClockWindow() {
    setTitle("Clock");
    resize(200,200);
    m_timerId = startTimer(1000);
}

void AnalogClockWindow::timerEvent(QTimerEvent * event) {
    if (event->timerId() == m_timerId) {
        renderLater();
    }
}

void AnalogClockWindow::render(QPainter *p) {
    static const QPoint hourHand[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-40),
    };

    static const QPoint minuteHand[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-70),
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    p->setRenderHint(QPainter::Antialiasing);
    p->translate(width() / 2, height() / 2);

    int side = qMin(width(), height());
    p->scale(side / 200.0, side / 200.0);

    p->setPen(Qt::NoPen);
    p->setBrush(hourColor);

    QTime time = QTime::currentTime();

    p->save();
    p->rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    p->drawConvexPolygon(hourHand, 3);
    p->restore();

    p->setPen(hourColor);

    for (int i =0 ; i < 12 ;++i ) {
        p->drawLine(88, 0,96,0);
        p->rotate(30.0);
    }

    p->setPen(Qt::NoPen);
    p->setBrush(minuteColor);

    p->save();
    p->rotate(6.0 * (time.minute() + time.second() / 60.0));
    p->drawConvexPolygon(minuteHand, 3);
    p->restore();

    p->setPen(minuteColor);
    for (int j = 0; j < 60 ; ++j) {
        p->drawLine(92,0,96,0);
        p->rotate(6.0);
    }


}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AnalogClockWindow clock;
    clock.show();
    return a.exec();
}
