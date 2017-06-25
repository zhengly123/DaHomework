#include "searchdialog.h"
#include "mainwindow.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setParent(parent);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(QSize(550,430));
    this->setModal(false);
    this->move(150,70);

    lab->setGeometry(50,70,450,50);
    lab->setStyleSheet("QLabel{font:bold,40px;color:rgb(0,0,0,255);}");
    ted->setGeometry(50,130,450,200);
    ted->setReadOnly(true);
    ted->setFrameStyle(0);
    ted->setStyleSheet("QTextEdit{font:bold,20px;color:rgb(0,0,0,200);}");
}

SearchDialog::~SearchDialog()
{
}
