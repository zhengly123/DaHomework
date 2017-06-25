#ifndef FEEDBACKDIALOG_H
#define FEEDBACKDIALOG_H

#include <QDialog>

class FeedbackDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit FeedbackDialog(QWidget *parent = 0);
        ~FeedbackDialog();

};

#endif // FEEDBACKDIALOG_H
