#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QRunnable>
#include <QObject>
#include <QDebug>
#include <QReadWriteLock>
#include <QTime>
#include <QSemaphore>

class mythread : public QObject, public QRunnable
{
        Q_OBJECT
public:
    mythread();

    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run();

signals:
    void isDone(int);   //处理完成信号
    void mySignal();    //注意！要使用信号，采用QObejct 和 QRunnable多继承，记得QObject要放在前面

public slots:
    //接收主线程的消息
    void recMegFromMain(QString);
};

class mythread1 : public QObject, public QRunnable
{
    Q_OBJECT
public:

    void run();
};

class mythread2  : public QObject, public QRunnable
{
    Q_OBJECT
public:

    void run();
};

class mythread3  : public QObject, public QRunnable
{
    Q_OBJECT
public:

    void run();
};

class mythread4  : public QObject, public QRunnable
{
    Q_OBJECT
public:

    void run();
};
#endif // MYTHREAD_H
