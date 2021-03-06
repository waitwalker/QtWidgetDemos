#ifndef RASTERWINDOW_H
#define RASTERWINDOW_H

#include <QWindow>
#include <QtGui>


class RasterWindow : public QWindow
{
    Q_OBJECT
public:
    // 显式构造函数
    explicit RasterWindow(QWindow *parent = nullptr);

    virtual void render(QPainter *painter);

    ~RasterWindow();
public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QBackingStore *m_backingStore;
};

#endif // RASTERWINDOW_H
