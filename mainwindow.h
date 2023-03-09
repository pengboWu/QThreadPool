#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include "mythread.h"
#include <QDebug>
#include <QMessageBox>
#include <QThreadPool>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void dealDone();   //线程槽函数

    void mySlot();

    void receiveMsgFromThread(int);

    void sengMsgToThreadBtn();

private:
    Ui::MainWindow *ui;

    QThreadPool pool;

    mythread* task = new mythread();
    mythread1* task1 = new mythread1();
    mythread2* task2 = new mythread2();
    mythread3* task3 = new mythread3();
    mythread4* task4 = new mythread4();

signals:
    //给子线程发消息
    void sengMsgToThread(QString);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
};
#endif // MAINWINDOW_H
