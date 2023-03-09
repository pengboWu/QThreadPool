#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QReadWriteLock>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置最大线程数为3的一个线程池
    pool.setMaxThreadCount(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sengMsgToThreadBtn()
{
    emit sengMsgToThread("hello");
}

// 定义槽函数 mySlot()
void MainWindow::mySlot()
{
    QMessageBox::about(this,"Tsignal", "响应线程中的mySlot函数");
}

//接收线程函数
void MainWindow::receiveMsgFromThread(int i)
{
    QString str = QString::number(i);
    qDebug()<<str;
}

void MainWindow::dealDone()
{
    ui->label->setText("线程停止");
    //停止线程
}

void MainWindow::on_pushButton_8_clicked()
{
    //QThread::sleep(1);
    //pool.waitForDone();           //等待任务结束
    on_pushButton_clicked();
    on_pushButton_3_clicked();
    on_pushButton_4_clicked();
    on_pushButton_5_clicked();
    on_pushButton_6_clicked();

    //启动线程，处理数据
    ui->label->setText("start");
}

void MainWindow::on_pushButton_2_clicked()
{
    pool.releaseThread();
//    停止线程
    dealDone();
    sengMsgToThreadBtn();
}

void MainWindow::on_pushButton_7_clicked()
{
    qDebug() << "on_pushButton_7_clicked()";
    qDebug() <<pool.activeThreadCount();
    //sengMsgToThreadBtn();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked()";
    pool.start(task);             //任务放进线程池
    task->setAutoDelete(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "on_pushButton_3_clicked()";
    pool.start(task);             //任务放进线程池
    task->setAutoDelete(false);
    /*
    pool.start(task1);
    task1->setAutoDelete(false);
    */
}

void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "on_pushButton_4_clicked()";
    pool.start(task);             //任务放进线程池

    //pool.start(task2);
}

void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << "on_pushButton_5_clicked()";
    pool.start(task);             //任务放进线程池
    //pool.start(task3);
}

void MainWindow::on_pushButton_6_clicked()
{
    qDebug() << "on_pushButton_6_clicked()";
    pool.start(task);             //任务放进线程池
    //pool.start(task4);
}
