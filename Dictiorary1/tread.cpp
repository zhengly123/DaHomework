#include "tread.h"
#include <QDebug>

Thread::Thread()
{
    stopped = false;
}

void Thread::run()
{
    res = new Responsehtml;
    while(!stopped)
    {
        QString htmll = res->gethttp();//htmll为从服务器接收到的消息，同时发送
        printmessage();
    }
    stopped = false;
}

void Thread::stop()
{
    stopped = true;
}

void Thread::setMessage(QString message)
{
    messageStr = message;
}

void Thread::printmessage()

{
    qDebug()<<messageStr;
    sleep(1);
}

