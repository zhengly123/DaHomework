#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>
#include <QString>

class BookDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit BookDialog(QWidget *parent = 0);
        ~BookDialog();

        int wordkind=0;//单词的类属
        int correctanswer=1;//解析得到的答案
        int useranswer=2;//用户给出的答案
        bool result=false;//用户答题结果
        QString word=0;//得到的单词信息

        QPushButton *btn1=new QPushButton(tr("CET"),this);
        QPushButton *btn2=new QPushButton(tr("考研"),this);
        QPushButton *btn3=new QPushButton(tr("我的单词"),this);
        QPushButton *btn4=new QPushButton(tr("next"),this);
        QLabel *lab=new QLabel(this);
        QRadioButton *btn5=new QRadioButton(this);
        QRadioButton *btn6=new QRadioButton(this);
        QRadioButton *btn7=new QRadioButton(this);
        QRadioButton *btn8=new QRadioButton(this);

    public slots:
        void btn1_clicked();
        void btn2_clicked();
        void btn3_clicked();
        void btn4_clicked();
        void btn5_clicked();
        void btn6_clicked();
        void btn7_clicked();
        void btn8_clicked();

    public:
        void getwords();//向服务器请求单词，并汇报上一次对错情况
        void showwords();//解析并显示单词，设置答案
        void check();//检查答题对错情况
        void feed();//告诉用户对错情况

};

#endif // BOOKDIALOG_H
