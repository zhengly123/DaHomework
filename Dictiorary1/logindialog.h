#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>


class LoginDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit LoginDialog(QWidget *parent = 0);
        ~LoginDialog();

        bool state=true;

        QLabel *label1=new QLabel(tr("username"),this);
        QLabel *label2=new QLabel(tr(" 密码"),this);
        QPushButton *btn1=new QPushButton(tr("确认"),this);
        QPushButton *btn2=new QPushButton(tr("取消"),this);
        QPushButton *btn3=new QPushButton(tr("没有用户名？点我注册"),this);
        QLineEdit *led1=new QLineEdit(this);
        QLineEdit *led2=new QLineEdit(this);

    public slots:
        void btn1_clicked();
        void btn3_clicked();

    public:
        QString Send(QString username,QString password);
        QString Register(QString username,QString password);
        void style();
};

#endif // LOGINDIALOG_H
