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
