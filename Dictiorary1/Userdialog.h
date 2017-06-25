#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QString>

class UserDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit UserDialog(QWidget *parent = 0);
        ~UserDialog();

        bool islogin=false;//用户是否登录
        QString username=tr("您尚未登录,点此登录");
        QString userifo=tr("暂无用户信息");
        QString friends=0;

        QTextEdit *ted1=new QTextEdit(this);
        QTextEdit *ted2=new QTextEdit(this);
        QPushButton *btn1=new QPushButton(username,this);
        QPushButton *btn2=new QCommandLinkButton(tr("好友列表"),this);

    public slots:
        void showLoginDialog();
        void showFriends();
};

#endif // USERDIALOG_H
