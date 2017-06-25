#include "welcomedialog.h"
#include <QLabel>
#include <QDialog>

WelcomeDialog::WelcomeDialog(QWidget *parent):QDialog(parent)
{
    this->setParent(parent);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(QSize(550,430));
    this->setModal(false);
    this->move(150,70);

    lab1->setGeometry(400,300,100,50);
    lab1->setText(tr("Welcome!"));
}

WelcomeDialog::~WelcomeDialog()
{

}
