#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pianokey.h"
#include <QTimer>
#include <QKeyEvent>
#include <QTextStream>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tim=new QElapsedTimer;
    tim->start();
    setFocusPolicy(Qt::StrongFocus); //** 获得焦点
    this->installEventFilter(this);

    c=&ccc;

    file.setFileName("myfile.txt");
    file.open(QIODevice::WriteOnly);
}

bool MainWindow::eventFilter(QObject * obj,QEvent * event){

    if(event->type() == QEvent::KeyPress)
    {
        QTextStream data(&file);
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        //** 改变延音效果 **//
        if (keyEvent->key() == Qt::Key_Space&&keyEvent->isAutoRepeat()==false)
        {
            TenutoChange();
        }
        //** Tab 键单独处理 **//
        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==false)
        {
            c->Q_Key.TenutoChange(Is_tenuto_space);
            c->Q_KeyPlay(tim->elapsed());
            data<<c->Q_Key;
            return true;
        }
    }
    return false;
};


void MainWindow::TenutoChange(void){
    if(Is_tenuto_space==0) Is_tenuto_space=1;
    else Is_tenuto_space=0;
};

void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug()<<"Enter Press";

    qDebug()<<event->key();

    if(event->isAutoRepeat()==false){
        QTextStream data(&file);
        switch (event->key()) {
        case Qt::Key_E:
            c->E_Key.TenutoChange(Is_tenuto_space);
            c->E_KeyPlay(tim->elapsed());
            data<<c->E_Key;
            break;
        case Qt::Key_Q:
            break;
        }
    }
};
/*void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->isAutoRepeat()==false){
        switch (event->key()) {
        case Qt::Key_E:
            if(!c.E_Key.GetPressmode()){
                c.E_Key.timer->stop();
                c.E_KeyStop();
                qDebug()<<"short";
            }
            else
                {//记录时间（未书写）//
                c.E_KeyStop();
                c.E_Key.PressmodeChange();
                qDebug()<<"Long";
            }
            break;
        case Qt::Key_Q:
            if(!c.Q_Key.GetPressmode()){
                c.Q_Key.timer->stop();
                c.Q_KeyStop(150);
                qDebug()<<"short";
            }
            else
                {//记录时间（未书写）//
                c.Q_KeyStop();
                c.Q_Key.PressmodeChange();
                qDebug()<<"Long";
            }
            break;
        }
    }
};*/

void MainWindow::Record(QString filename){
    if(Is_record) Is_record=0;
    else Is_record=1;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly);
};
MainWindow::~MainWindow()
{
    delete ui;
}

