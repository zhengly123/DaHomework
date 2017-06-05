#ifndef TREAD_H
#define TREAD_H
#include <QThread>
#include <iostream>
#include "huanyu.h"
class Thread:public QThread
{
    Q_OBJECT
    public:
        Thread();
        void setMessage(QString message);
        void stop();
    protected:
        void run();
        void printmessage();
    private:
        Responsehtml *res;
        QString messageStr;
        volatile bool stopped;
};
#endif // TREAD_H
