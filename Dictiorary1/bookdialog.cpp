#include "bookdialog.h"

BookDialog::BookDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setParent(parent);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(QSize(550,430));
    this->setModal(false);
    this->move(150,70);

    btn1->setGeometry(50,30,70,30);
    btn1->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    btn2->setGeometry(170,30,70,30);
    btn2->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    btn3->setGeometry(290,30,70,30);
    btn3->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    btn4->setGeometry(320,290,70,30);
    btn4->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    lab->setGeometry(50,70,450,50);
    btn5->setGeometry(50,120,450,40);
    btn5->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);border-radius:7px;font:bold 17px;color:rgb(0,0,0,200);}");
    btn6->setGeometry(50,160,450,40);
    btn6->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);border-radius:7px;font:bold 17px;color:rgb(0,0,0,200);}");
    btn7->setGeometry(50,200,450,40);
    btn7->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);border-radius:7px;font:bold 17px;color:rgb(0,0,0,200);}");
    btn8->setGeometry(50,240,450,40);
    btn8->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);border-radius:7px;font:bold 17px;color:rgb(0,0,0,200);}");

    connect(btn1,&QPushButton::clicked,this,&BookDialog::btn1_clicked);
    connect(btn2,&QPushButton::clicked,this,&BookDialog::btn2_clicked);
    connect(btn3,&QPushButton::clicked,this,&BookDialog::btn3_clicked);
    connect(btn4,&QPushButton::clicked,this,&BookDialog::btn4_clicked);
    connect(btn5,&QRadioButton::clicked,this,&BookDialog::btn5_clicked);
    connect(btn6,&QRadioButton::clicked,this,&BookDialog::btn6_clicked);
    connect(btn7,&QRadioButton::clicked,this,&BookDialog::btn7_clicked);
    connect(btn8,&QRadioButton::clicked,this,&BookDialog::btn8_clicked);

}

void BookDialog::btn1_clicked()
{
    wordkind=1;
    getwords();
    showwords();
}

void BookDialog::btn2_clicked()
{
    wordkind=2;
    getwords();
    showwords();
}

void BookDialog::btn3_clicked()
{
    wordkind=3;
    getwords();
    showwords();
}

void BookDialog::btn4_clicked()
{
    getwords();
    showwords();
}

void BookDialog::btn5_clicked()
{
    useranswer=1;
    check();
    feed();
}

void BookDialog::btn6_clicked()
{
    useranswer=2;
    check();
    feed();
}

void BookDialog::btn7_clicked()
{
    useranswer=3;
    check();
    feed();
}

void BookDialog::btn8_clicked()
{
    useranswer=4;
    check();
    feed();
}

void BookDialog::getwords()
{
    switch (wordkind)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    btn5->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);}");
    btn6->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);}");
    btn7->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);}");
    btn8->setStyleSheet("QRadioButton{background-color:rgb(255,255,255);}");
}

void BookDialog::showwords()
{

}

void BookDialog::check()
{
    if(correctanswer==useranswer)
        result=true;
    else
        result=false;
}

void BookDialog::feed()
{
    switch(useranswer)
    {
        case 1:
            btn5->setStyleSheet("QRadioButton{background-color:rgb(255,0,0);}");
            break;
        case 2:
            btn6->setStyleSheet("QRadioButton{background-color:rgb(255,0,0);}");
            break;
        case 3:
            btn7->setStyleSheet("QRadioButton{background-color:rgb(255,0,0);}");
            break;
        case 4:
            btn8->setStyleSheet("QRadioButton{background-color:rgb(255,0,0);}");
            break;
        default:
            break;
    }
    switch(correctanswer)
    {
        case 1:
            btn5->setStyleSheet("QRadioButton{background-color:rgb(0,255,0);}");
            break;
        case 2:
            btn6->setStyleSheet("QRadioButton{background-color:rgb(0,255,0,255);}");
            break;
        case 3:
            btn7->setStyleSheet("QRadioButton{background-color:rgb(0,255,0,255);}");
            break;
        case 4:
            btn8->setStyleSheet("QRadioButton{background-color:rgb(0,255,0,255);}");
            break;
        default:
            break;
    }
}

BookDialog::~BookDialog()
{

}
