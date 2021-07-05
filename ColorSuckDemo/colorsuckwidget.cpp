#include "colorsuckwidget.h"
#include "ui_colorsuckwidget.h"

#include <QMouseEvent>
#include <QTimer>
// 单例模式
ColorSuckWidget *ColorSuckWidget::instance = 0;
ColorSuckWidget *ColorSuckWidget::sharedInstance()
{
    if (!instance) {
        // 同步机制
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!instance) {
            instance = new ColorSuckWidget;
        }
    }
    return instance;
}

ColorSuckWidget::ColorSuckWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSuckWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("颜色选择");
    // 网格布局
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11,11,11,11);

    // 垂直布局
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(0);

    labColor = new QLabel();
    labColor->setText("+");
    labColor->setStyleSheet("background-color:rgb(255,107,107);color:rgb(250,250,250)");
    labColor->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPixelSize(35);
    font.setBold(true);
    labColor->setFont(font);

    QSizePolicy sizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labColor->sizePolicy().hasHeightForWidth());
    labColor->setSizePolicy(sizePolicy);
    labColor->setMinimumSize(QSize(80, 70));
    labColor->setMaximumSize(QSize(80, 70));
    labColor->setCursor(QCursor(Qt::CrossCursor));
    labColor->setFrameShape(QFrame::StyledPanel);
    labColor->setFrameShadow(QFrame::Sunken);
    verticalLayout->addWidget(labColor);

    label = new QLabel(this);
    label->setText("当前颜色");
    label->setMinimumSize(QSize(0, 18));
    label->setStyleSheet("background-color:rgb(0,0,0); color:rgb(200,200,200)");
    label->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label);
    gridLayout->addLayout(verticalLayout, 0,0,3,1);

    labWeb = new QLabel(this);
    labWeb->setText("16进制值:");
    gridLayout->addWidget(labWeb,0,1,1,1);

    // void addWidget(QWidget *, int row, int column, Qt::Alignment = Qt::Alignment());
    txtWeb = new QLineEdit(this);
    gridLayout->addWidget(txtWeb,0,2,1,1);

    labRGB = new QLabel(this);
    gridLayout->addWidget(labRGB,1,1,1,1);

    txtRGB = new QLineEdit(this);
    gridLayout->addWidget(txtRGB,1,2,1,1);

    labPoint = new QLabel(this);
    gridLayout->addWidget(labPoint,2,1,1,1);

    txtPoint = new QLineEdit(this);
    gridLayout->addWidget(txtPoint,2,2,1,1);

    label->setText("当前颜色");
    labWeb->setText("16进制颜色:");
    labRGB->setText("RGB值:");
    labPoint->setText("坐标值:");

    this->setLayout(gridLayout);
    this->setFixedSize(350, 120);
    cp = QApplication::clipboard();
    pressed = false;

    timer = new QTimer(this);
    timer->setInterval(100);
    timer->start();
    connect(timer,&QTimer::timeout, [=](){
        qDebug()<<"监听事件";
        if (!pressed) {
            return;
        }

        int x = QCursor::pos().x();
        int y = QCursor::pos().y();
        txtPoint->setText(tr("x:%1 y%2").arg(x).arg(y));

#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
        QPixmap pixMap = QPixmap::grabWindow(qApp->desktop()->winId(),x,y,2,2);
#else
        QScreen *screen = qApp->primaryScreen();
        // 根据坐标获取指定屏幕
        QPixmap pixMap = screen->grabWindow(0,x,y,2,2);
#endif
        int red = 0, green = 0, blue = 0;
        QString strDecimalValue, strHex;
        if (!pixMap.isNull()) {
            QImage image = pixMap.toImage();
            if (!image.isNull()) {
                QColor color = image.pixel(0,0);
                red = color.red();
                green = color.green();
                blue = color.blue();
                QString strRed = tr("%1").arg(red & 0xFF,2,16,QChar('0'));
                QString strGreen = tr("%1").arg(green & 0xFF,2,16,QChar('0'));
                QString strBlue = tr("%1").arg(blue & 0xFF,2,16,QChar('0'));

                strDecimalValue = tr("%1, %2, %3").arg(red).arg(green).arg(blue);
                strHex = tr("#%1%2%3").arg(strRed.toUpper()).arg(strGreen.toUpper()).arg(strBlue.toUpper());

            }
        }

        // 根据背景色自动计算合适的前景色
        QColor color(red,green,blue);
        double gray = (0.299 * color.red() + 0.587 * color.green() + 0.114 * color.blue()) / 255;
        QColor textColor = gray > 0.5 ? Qt::black: Qt::white;

        QString str = tr("background:rgb(%1);color:rgb(%2)").arg(strDecimalValue).arg(textColor.name());
        labColor->setStyleSheet(str);
        txtRGB->setText(strDecimalValue);
        txtWeb->setText(strHex);

    });
}

ColorSuckWidget::~ColorSuckWidget()
{
    delete ui;
}

void ColorSuckWidget::mousePressEvent(QMouseEvent *event)
{
    if (labColor->rect().contains(event->pos())) {
        pressed = true;
    }
}

void ColorSuckWidget::mouseReleaseEvnet(QMouseEvent *event)
{
    pressed = false;
}

void ColorSuckWidget::showColorValue()
{

}
