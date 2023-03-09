#include "mythread.h"
#include <QMutex>
#include <QRandomGenerator>
#include <QWaitCondition>
#include <QThread>

/*
如果乱码就加上QStringLiteral();
#pragma execution_character_set("GB2312")
*/

mythread::mythread()
{
}

void mythread::run()
{
    for (int i = 0; i < 10; i++) {
        QThread::sleep(2);
        qDebug()<< QStringLiteral("PrintTask run 被调用，调用线程ID为：") << QThread::currentThread() << QStringLiteral( " 线程1打印数据：") <<QString::number(i);
    }
    //emit isDone(1);  //发送完成信号
}

void mythread::recMegFromMain(QString str)
{
    qDebug()<< "子线程接收到" <<str;
}

void mythread1::run()
{
    qDebug()<< QStringLiteral("PrintTask run 被调用，调用线程ID为：") << QThread::currentThread() ;
    for (int i = 10; i < 20; i++) {
        QThread::sleep(2);
        qDebug()<< "线程2打印数据：" <<QString::number(i);
    }
    //emit isDone(1);  //发送完成信号
}

void mythread2::run()
{
    qDebug()<< "PrintTask run 被调用，调用线程ID为：" << QThread::currentThread() ;
    for (int i = 20; i < 30; i++) {
        QThread::sleep(2);
        qDebug()<< "线程3打印数据：" <<QString::number(i);
    }
    //emit isDone(1);  //发送完成信号
}

void mythread3::run()
{
    qDebug()<< "PrintTask run 被调用，调用线程ID为：" << QThread::currentThread() ;
    for (int i = 30; i < 40; i++) {
        QThread::sleep(2);
        qDebug()<< "线程4打印数据：" <<QString::number(i);
    }
    //emit isDone(1);  //发送完成信号
}

void mythread4::run()
{
    qDebug()<< "PrintTask run 被调用，调用线程ID为：" << QThread::currentThread() ;
    for(int i = 40; i < 50; i++) {
        QThread::sleep(2);
        qDebug()<< "线程5打印数据：" <<QString::number(i);
    }
    //emit isDone(1);  //发送完成信号
}
