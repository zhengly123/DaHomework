#include "pkdialog.h"

PkDialog::PkDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setParent(parent);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(QSize(550,430));
    this->setModal(false);
    this->move(150,70);

    btn1->setGeometry(20,30,120,30);
    connect(btn1,&QPushButton::clicked,this,&PkDialog::findpeople);
}

void PkDialog::findpeople()
{

}

PkDialog::~PkDialog()
{
}
