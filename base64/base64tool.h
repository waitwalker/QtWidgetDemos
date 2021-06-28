#ifndef BASE64TOOL_H
#define BASE64TOOL_H
#include <QImage>
#include <QString>


/*
    通过提供静态函数调用
*/

class Base64Tool
{
public:
    // 无参数构造函数
    Base64Tool();

    // 图片转base64编码
    static QString base64From(const QImage &image);

    // base64 转换为图片
    static QImage imageFrom(const QString &base64);

    //汉字转base64编码  重载
    static QString base64From(const QString &text);

    //base64编码转汉字
    static QString textFrom(const QString &base64);

    ~Base64Tool();

private:
    // 图片转换为字节数组
    static QByteArray imageDataFrom(const QImage &image);
};

#endif // BASE64TOOL_H
