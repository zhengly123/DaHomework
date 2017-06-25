#include "userdialog.h"
#include "logindialog.h"
#include <QString>
#include <QFile>

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setParent(parent);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(QSize(550,430));
    this->setModal(false);
    this->move(150,70);

    btn1->setGeometry(20,30,250,30);
    btn2->setGeometry(280,30,250,30);
    ted1->setGeometry(20,60,250,330);
    ted1->setText(userifo);
    ted2->setGeometry(280,60,250,330);

    connect(btn1,&QPushButton::clicked,this,&UserDialog::showLoginDialog);
    connect(btn2,&QCommandLinkButton::clicked,this,&UserDialog::showFriends);


}

void UserDialog::showLoginDialog()
{
    if(!islogin)
    {
        LoginDialog dlg(this);
        if(dlg.exec()==QDialog::Accepted)
        {
            //登陆成功后的操作
            islogin = true;
            this->show();
        }
    }
    else
    {
        //登录成功后的操作
    }

}

void UserDialog::showFriends()
{

}

UserDialog::~UserDialog()
{
}
