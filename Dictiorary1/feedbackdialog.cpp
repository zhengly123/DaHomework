#include "feedbackdialog.h"

FeedbackDialog::FeedbackDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setParent(parent);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(QSize(550,430));
    this->setModal(false);
    this->move(150,70);

}

FeedbackDialog::~FeedbackDialog()
{
}
