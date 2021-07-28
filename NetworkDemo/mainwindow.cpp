#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkReply>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    qDebug()<<manager->supportedSchemes();

    QString baseURL = "https://school.etiantian.com/api-study-service/api/course/v2.3/courses";
    QNetworkRequest request;
    request.setRawHeader("Authorization","Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJkZXRhaWwiOnsidXNlcklkIjo5NjE1NjkyLCJ1c2VyTmFtZSI6Inh3eDE4NjAwMDAwMDAxIiwicGFzc3dvcmQiOiIiLCJ1c2VySWRlbnRpdHkiOjMsImVuYWJsZSI6MSwic2Nob29sVXNlcklkIjowLCJzY2hvb2xJZCI6MCwic2Nob29sVXNlclJlZiI6bnVsbCwic2Nob29sR3JvdXBJZCI6bnVsbCwicm9sZXMiOls1XSwidXJsTGlzdCI6bnVsbH0sImV4cCI6MTYyNzQ3MzQzMiwidXNlcl9uYW1lIjoieHd4MTg2MDAwMDAwMDEiLCJqdGkiOiJlYjY1OTYyMS0yM2QzLTQ0ZGYtOTc3YS0zNmQ2OTcxMGVjOTMiLCJjbGllbnRfaWQiOiIyRjVFRTU5MzA1MDU5NTBGQTVEMEYyMTUxNzFDMTVGOSIsInNjb3BlIjpbImFsbCIsIndlYiIsIm1vYmlsZSJdfQ.n0UF28o_Idp1B8O_MNBogXQBkw9sOuKEznHtYgw13gE");
    request.setUrl(baseURL);

    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,[=](QNetworkReply *reply){

        int statusCode  = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug()<<statusCode;
        if (statusCode == 200) {
            // 准备读数据
            QTextCodec *codec = QTextCodec::codecForName("utf8");
            QString all = codec->toUnicode(reply->readAll());
            qDebug() << all;

            QJsonParseError jsonError;
            QJsonDocument document = QJsonDocument::fromJson(all.toUtf8(),&jsonError);

            if (jsonError.error != QJsonParseError::NoError) {
                qDebug()<<"JSON解析失败";
            }

            if (document.isObject()) {
                QJsonObject obj = document.object();
                QJsonValue value = obj.take("msg");

                qDebug()<<value.toString();
            }

        }

        return 0;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

