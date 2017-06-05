#ifndef LOGFILEDIALOG_H
#define LOGFILEDIALOG_H

#include <QDialog>

class LogfileDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit LogfileDialog(QWidget *parent = 0);
        ~LogfileDialog();

};

#endif // LOGFILEDIALOG_H

