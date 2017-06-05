#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QTextEdit>

class SearchDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit SearchDialog(QWidget *parent = 0);
        ~SearchDialog();

        QLabel *lab=new QLabel(this);
        QTextEdit *ted=new QTextEdit(this);

};

#endif // SEARCHDIALOG_H
