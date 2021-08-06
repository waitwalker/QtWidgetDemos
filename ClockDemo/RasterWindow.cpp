#include "RasterWindow.h"

RasterWindow::RasterWindow(QWindow *parent):QWindow(parent),m_backingStore(new QBackingStore(this))
{
    setGeometry(100,100,300,200);
}

void RasterWindow::render(QPainter *painter)
{
    // 绘制文字
    painter->drawText(QRectF(0,0,width(),height()),Qt::AlignCenter,QStringLiteral("QWindow"));
}

RasterWindow::~RasterWindow()
{

}

void RasterWindow::renderLater()
{
    requestUpdate();
}

void RasterWindow::renderNow()
{
    if (!isExposed()) {
        return;
    }
    QRect rect(0,0,width(),height());
    m_backingStore->beginPaint(rect);

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(0,0,width(), height(),QGradient::NightFade);
    render(&painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

bool RasterWindow::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void RasterWindow::resizeEvent(QResizeEvent *event)
{
    m_backingStore->resize(event->size());
}

void RasterWindow::exposeEvent(QExposeEvent *event)
{
    if (isExposed())
        renderNow();
}

