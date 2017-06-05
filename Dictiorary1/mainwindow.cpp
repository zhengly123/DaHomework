#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRect>
#include <QObject>
#include <QPainter>
#include <QImage>
#include <QMessageBox>
#include <QIcon>
#include <QApplication>
#include "json/json.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->resize(QSize(700,500));

    LoadBasicDictJson loader;

    loader.Load("res\\dict.json", dict);
    root= (Trie *)malloc(sizeof(Trie));
        for(int i=0;i<MAX;i++)
        {
            root->next[i]=NULL;
        }
        root->isStr=false;
    opt(root,dict.ToWordList());
    //qDebug()<<dict.ToWordList().empty();
    //qDebug()<<(root==NULL)<<"mainwindow";
    titlelab=new QLabel(this);
    titlelab->setGeometry(5,5,140,60);
    getwordled=new SearchBox(tr(""),this,root);
    getwordled->setGeometry(200,20,250,30);
    searchbtn=new QPushButton(tr("查询"),this);
    searchbtn->setGeometry(450,20,50,30);
    minbtn=new QPushButton(this);
    minbtn->setGeometry(626,20,36,30);
    closebtn=new QPushButton(this);
    closebtn->setGeometry(662,20,36,30);
    userbtn=new QPushButton(tr("用户"),this);
    userbtn->setGeometry(35,100,80,30);
    bookbtn=new QPushButton(tr("wordbook"),this);
    bookbtn->setGeometry(35,150,80,30);
    pkbtn=new QPushButton(tr("对战"),this);
    pkbtn->setGeometry(35,200,80,30);
    logfilebtn=new QPushButton(tr("日志"),this);
    logfilebtn->setGeometry(35,280,80,30);
    feedbackbtn=new QPushButton(tr("反馈"),this);
    feedbackbtn->setGeometry(35,330,80,30);
    backbtn=new QPushButton(tr("回主界面"),this);
    backbtn->setGeometry(35,380,80,30);
    connect(getwordled,SIGNAL(testsignal()),this,SLOT(showSearchDialog()));
    connect(searchbtn,&QPushButton::clicked,this,&MainWindow::showSearchDialog);
    connect(minbtn,&QPushButton::clicked,this,&MainWindow::showMinimized);
    connect(closebtn,&QPushButton::clicked,this,&MainWindow::close);
    connect(userbtn,&QPushButton::clicked,this,&MainWindow::showUserDialog);
    connect(bookbtn,&QPushButton::clicked,this,&MainWindow::showBookDialog);
    connect(pkbtn,&QPushButton::clicked,this,&MainWindow::showPkDialog);
    connect(logfilebtn,&QPushButton::clicked,this,&MainWindow::showLogfileDialog);
    connect(feedbackbtn,&QPushButton::clicked,this,&MainWindow::showFeedbackDialog);
    connect(backbtn,&QPushButton::clicked,this,&MainWindow::showWelcomeDialog);

    allhide();
    welcomedia->show();
    style();
}

void MainWindow::style()
{
    paintEvent(0);
    loadImage();

    minbtn->setStyleSheet("QPushButton{background-color:rgb(0,0,0,0);}");
    closebtn->setStyleSheet("QPushButton{background-color:rgb(0,0,0,0);}");
    searchbtn->setStyleSheet("QPushButton{background-color:rgb(255,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    userbtn->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    pkbtn->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    bookbtn->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    feedbackbtn->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    logfilebtn->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    backbtn->setStyleSheet("QPushButton{background-color:rgb(180,180,180,100);border-radius:7px;font:bold 15px;color:rgb(0,0,0,150);}");
    getwordled->setStyleSheet("QLineEdit{border-radius:7px;font:bold;}");

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(0,0,700,70,QColor(255,69,32,255));
    painter.fillRect(0,70,700,430,Qt::white);
    painter.setPen(Qt::gray);
    painter.drawLine(150,70,150,500);
    painter.drawLine(20,255,130,255);
}

void MainWindow::loadImage()
{
    QImage* img=new QImage,*scaledimg=new QImage;
    if(!img->load(":/61a58PICtPr_1024.jpg"))
    {
        QMessageBox::information(this,
                                 tr("打开图像失败"),
                                 tr("打开图像失败!"));
    }
    int Owidth=img->width(),Oheight=img->height();
    int Mul;
    if(Owidth/140>=Oheight/60)
        Mul=Owidth/140;
    else
        Mul=Oheight/60;
    int Fwidth=Owidth/Mul;
    int Fheight=Oheight/Mul;
    *scaledimg=img->scaled(Fwidth,Fheight,Qt::IgnoreAspectRatio);
    titlelab->setPixmap(QPixmap::fromImage(*scaledimg));

    QIcon minbtn_ico(":/min.jpg");
    QIcon closebtn_ico(":/close.jpg");
    minbtn->setIcon(minbtn_ico);
    closebtn->setIcon(closebtn_ico);
}

void MainWindow::allhide()
{
    searchdia->hide();
    userdia->hide();
    bookdia->hide();
    pkdia->hide();
    logfiledia->hide();
    feedbackdia->hide();
    welcomedia->hide();
}

void MainWindow::getword()
{
    target=getwordled->text();
}

QString MainWindow::getmain(QString target)
{
    if(dict.Search(target.toStdString()).meaning.empty())
        return tr("no explanation");
    BasicWord kk = dict.Search(target.toStdString());
    QString out = "";
    out+=tr("phonetic:|");
    out += QString::fromStdString(kk.phonetic);
    out+="|\n";
    out += tr("meaning:\n");
    vector<Meaning> ivector = kk.meaning;
    qDebug()<<(int)(dict.Search(target.toStdString()).meaning.size());
    for (auto iter=ivector.begin();iter!=ivector.end();iter++)
        {
            out += QString::fromStdString((*iter).part_of_speech) + " " +QString::fromStdString((*iter).chinese_meaning) + "\n";
        }
    return out;
    //return QString::fromStdString(dict.Search(target.toStdString()).phonetic);
}

void MainWindow::showSearchDialog()
{
    allhide();
    qDebug()<<33333;
    searchdia->show();
    getword();
    searchdia->lab->setText(target);
    searchdia->ted->setText(getmain(target));
}

void MainWindow::showUserDialog()
{
    allhide();
    userdia->show();
}

void MainWindow::showBookDialog()
{
    allhide();
    bookdia->show();
}

void MainWindow::showPkDialog()
{
    allhide();
    pkdia->show();
}

void MainWindow::showLogfileDialog()
{
    allhide();
    logfiledia->show();
}

void MainWindow::showFeedbackDialog()
{
    allhide();
    feedbackdia->show();
}

void MainWindow::showWelcomeDialog()
{
    allhide();
    welcomedia->show();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mMoveing = true;
    mMovePosition = event->globalPos() - pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)&&mMovePosition.x()<700&&mMovePosition.y()<70)
    {
        QPoint temp=event->globalPos()-mMovePosition;
        move(temp);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}
/*
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mMoveing = true;
    //记录下鼠标相对于窗口的位置
    //event->globalPos()鼠标按下时，鼠标相对于整个屏幕位置
    //pos() this->pos()鼠标按下时，窗口相对于整个屏幕位置
    mMovePosition = event->globalPos() - pos();
    return MainWindow::mousePressEvent(event);
}

//重写鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //(event->buttons() && Qt::LeftButton)按下是左键
    //鼠标移动事件需要移动窗口，窗口移动到哪里呢？就是要获取鼠标移动中，窗口在整个屏幕的坐标，然后move到这个坐标，怎么获取坐标？
    //通过事件event->globalPos()知道鼠标坐标，鼠标坐标减去鼠标相对于窗口位置，就是窗口在整个屏幕的坐标
    if (mMoveing && (event->buttons() && Qt::LeftButton))
    {
        QPoint temp=event->globalPos()-mMovePosition;
        move(temp);

    }
    return MainWindow::mouseMoveEvent(event);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}
*/
MainWindow::~MainWindow()
{

}









