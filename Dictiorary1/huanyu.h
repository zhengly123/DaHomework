#ifndef HUANYU_H
#define HUANYU_H
#include <QCoreApplication>
#include<QDebug>
#include<QObject>
#include<QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include<QEventLoop>
#include<QtXml/QDomDocument>
#include<QtCore/QXmlStreamReader>
#pragma execution_character_set("UTF-8")
class Responsehtml
{

public:
    QNetworkAccessManager *accessManager;
    QNetworkRequest request;
    QNetworkReply *reply;
    QString gethttp(QByteArray post_data = "client=true")
      {
         QEventLoop temp_loop;
          QUrl url("http://183.172.80.157:23413/h.kkkkk");
              //QByteArray post_data="client=true";//上传的数据可以是QByteArray或者file类型
              accessManager=new QNetworkAccessManager();

              request.setUrl(url);
              /******************设置http的header***********************/
          //    request.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
        //      request.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");//上传文件
        //     request.setRawHeader("Content-Disposition","form-data;name='doc';filename='a.txt'");

        //      request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.79 Safari/537.36 Edge/14.14393");
            QObject::connect(accessManager,SIGNAL(finished(QNetworkReply*)),&temp_loop,SLOT(quit()));
           // qDebug()<<"start";
                reply=accessManager->post(request,post_data);//通过发送数据，返回值保存在reply指针里.
           temp_loop.exec();
             //finish为manager自带的信号，replyFinished是自定义的
            qDebug()<<"get";
           QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

           //无错误返回
           if(reply->error() == QNetworkReply::NoError)
           {
           //    download_Btn->setText("success");
               QByteArray bytes = reply->readAll();
               QString result(bytes);  //转化为字符串
               qDebug()<<(result)<<" this is back";
               return result;
           }
           else
           {
               //处理错误
        //        download_Btn->setText("failed");
           }

           reply->deleteLater();//要删除reply，但是不能在repyfinished里直接delete，要调用deletelater;

      }

    void replyFinished(QNetworkReply *reply){
        //获取响应的信息，状态码为200表示正常

    }


};
#endif // HUANYU_H
