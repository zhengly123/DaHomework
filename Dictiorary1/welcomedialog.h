#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

#include <QLabel>
#include <QDialog>

class WelcomeDialog:public QDialog
{
    public:
        WelcomeDialog(QWidget *parent=0);
        ~WelcomeDialog();

        QLabel *lab1=new QLabel(this);
};


#endif // WELCOMEDIALOG_H
