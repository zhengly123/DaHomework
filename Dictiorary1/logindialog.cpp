#include "logindialog.h"
#include "export.h"
#include "huanyu.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent)
{
    this->resize(QSize(400,300));
    label1->setGeometry(40,30,60,30);
    label2->setGeometry(40,90,60,30);
    btn1->setGeometry(80,210,80,30);
    btn2->setGeometry(240,210,80,30);
    btn3->setGeometry(100,160,200,20);
    led1->setGeometry(100,30,250,30);
    led1->setPlaceholderText(tr("请输入您的用户名"));
    led2->setGeometry(100,90,250,30);
    led2->setPlaceholderText(tr("input your password"));
    led2->setEchoMode(QLineEdit::Password);

    connect(btn1,&QPushButton::clicked,this,&LoginDialog::btn1_clicked);
    connect(btn2,&QPushButton::clicked,this,&LoginDialog::close);
    connect(btn3,&QPushButton::clicked,this,&LoginDialog::btn3_clicked);

    style();
}

void LoginDialog::style()
{
    this->setStyleSheet("LoginDialog{background-image:url(:/background3.jpg);}");
    label1->setStyleSheet("QLabel{background-color:rgb(0,0,0,0);font:bold 15px;}");
    label2->setStyleSheet("QLabel{background-color:rgb(0,0,0,0);font:bold 15px;}");
    led1->setStyleSheet("QLineEdit{border-radius:7px;font:regular 15px;}");
    led2->setStyleSheet("QLineEdit{border-radius:7px;font:regular 15px;}");
    btn1->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    btn2->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    btn3->setStyleSheet("QPushButton{background-color:rgb(0,0,0,0);font:regular,13px;color:rgb(0,100,255,200);}");
}

void LoginDialog::btn1_clicked()
{
    if(state)
    {
        //判断用户名和密码是否正确
        //如果错误则弹出警告框
        if(Send(led1->text().trimmed(), led2->text())=="send ok")//    Send返回的是服务器验证这个账号密码的对错
        {
          //  loginsuccess();//         执行成功的操作
            accept();
        }
        else
        {
            QMessageBox::warning(this,tr("警告:"),
                                 tr("用户名或密码错误!"),
                                 tr("确定"));
            //清除内容并定位光标
            led1->clear();
            led2->clear();
            led1->setFocus();
        }
    }
    else
    {
        if(Register(led1->text().trimmed(), led2->text())=="send ok")//    Register返回的是服务器验证这个账号密码的对错
        {
          //  loginsuccess();//         执行成功的操作
            accept();
        }
        else
        {
            QMessageBox::warning(this,tr("警告:"),
                                 tr("用户名已被注册!"),
                                 tr("确定"));
            //清除内容并定位光标
            led1->clear();
            led2->clear();
            led1->setFocus();
        }
    }
}

void LoginDialog::btn3_clicked()
{
    state=false;
    btn3->hide();
    btn1->setText(tr("注册"));
    //清除内容并定位光标
    led1->clear();
    led2->clear();
    led1->setFocus();
}

QString LoginDialog::Send(QString username, QString password)
{
    Responsehtml* mres = new Responsehtml;
    QString htmll = mres->gethttp(ExportMes_login(username.toLatin1(),password.toLatin1()));
    return htmll;
}

QString LoginDialog::Register(QString username, QString password)
{
    Responsehtml* mres2 = new Responsehtml;
    QString htmll = mres2->gethttp(ExportMes_register(username.toLatin1(),password.toLatin1()));
    return htmll;
}

LoginDialog::~LoginDialog()
{
}
