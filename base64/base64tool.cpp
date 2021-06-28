#include "base64tool.h"

#include <QBuffer>
#include <QDebug>

Base64Tool::Base64Tool()
{

}

QString Base64Tool::base64From(const QImage &image)
{
    qDebug()<<QString(imageDataFrom(image));
    return QString(imageDataFrom(image));
}

QImage Base64Tool::imageFrom(const QString &base64)
{
    QByteArray imageData = QByteArray::fromBase64(base64.toLatin1());
    QImage image;
    image.loadFromData(imageData);
    return image;
}

QString Base64Tool::base64From(const QString &text)
{
    qDebug()<<"文字转base64:"<<QString(text.toLocal8Bit().toBase64());
    return QString(text.toLocal8Bit().toBase64());
}

QString Base64Tool::textFrom(const QString &base64)
{
    QByteArray dataArray = QByteArray::fromBase64(base64.toLocal8Bit());
    return QString(dataArray);
}


Base64Tool::~Base64Tool()
{

}

QByteArray Base64Tool::imageDataFrom(const QImage &image)
{
    QByteArray imageData;
    QBuffer buffer(&imageData);
    image.save(&buffer,"JPG");
    imageData = imageData.toBase64();
    return imageData;
}
