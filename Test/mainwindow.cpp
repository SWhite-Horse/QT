#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QSound>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str1,str2,str3;
    str1=":/voice/";
    str2.setNum(1);
    str3=str1+str2+".wav";
    s= new QSound(str3);
    timr=new QTimer(this);
    tim=new QElapsedTimer;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_D&&event->isAutoRepeat()==false) {
        timr->start(200);
        st=tim->elapsed();
        qDebug()<<"起始时间"<<st;

    }


}
void MainWindow::keyReleaseEvent(QKeyEvent * event){
//    if(event->key()==Qt::Key_S&&event->isAutoRepeat()==false) {
//        ss->play();
//    }
//    if(event->key()==Qt::Key_A&&event->isAutoRepeat()==true&&ister==0) {
//        sss->play();
//        ister=1;
//    }
//    if(event->key()==Qt::Key_A&&event->isAutoRepeat()==false){
//        sss->stop();
//        ister=0;
////    }
//    if(event->key()==Qt::Key_D&&event->isAutoRepeat()==false&&ister==1) {
//        ister=0;
//        end=tim->elapsed();
//        qDebug()<<"终止时间"<<end;
//        qDebug()<<"时间间隔"<<end-st;
//    }
    if(event->key()==Qt::Key_D&&event->isAutoRepeat()==true&&ister==0){
        end=tim->elapsed();
        qDebug()<<"终止时间"<<end;
        qDebug()<<"时间间隔"<<end-st;
        ister=1;
        qDebug()<<ister;
    }
////    if(event->key()==Qt::Key_D&&event->isAutoRepeat()==true){
////        num=0;
////        qDebug()<<ss->state()<<num;
////    }
////    if(event->key()==Qt::Key_D&&event->isAutoRepeat()==false&&num==1) {
////         QTimer * tim=new QTimer(this);
////         tim->start(400);
////         connect(tim,&QTimer::timeout,[=](){
////            ss->stop();
////            tim->stop();
////         });

//    }
//    if(event->key()==Qt::Key_D&&event->isAutoRepeat()==false) {
//        s->stop();

//    }
//    if(event->key()==Qt::Key_S&&event->isAutoRepeat()==false) {
//        ss->stop();
//    }
//    if(event->key()==Qt::Key_A&&event->isAutoRepeat()==false) {
//        sss->stop();
//    }
};


MainWindow::~MainWindow()
{
    delete ui;
}

