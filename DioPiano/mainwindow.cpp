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

    setFocusPolicy(Qt::StrongFocus); //** 获得焦点
    this->installEventFilter(this);

    Record("myfile.txt");
    tone=&c; //**初始化为C大调
}

//***********************************************//
//***************** Press处理 ********************//
//***********************************************//

bool MainWindow::eventFilter(QObject * obj,QEvent * event){

    if(event->type() == QEvent::KeyPress)
    {
        QTextStream data(&file);
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        qDebug()<<keyEvent->key();
        //** 改变延音效果 **//
        if (keyEvent->key() == Qt::Key_Space&&keyEvent->isAutoRepeat()==false)
        {
            TenutoChange();
        }
        //** Tab 键单独处理 **//
//        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==false)
//        {
//            tone->Tab_Key.TenutoChange(Is_tenuto_space);
//            tone->Tab_KeyPlay(tim->elapsed());
//            if(Is_record) data<<tone->Tab_Key;
//            return true;
//        }
        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==true)
        {
            return true;
        }
        if (keyEvent->key() == Qt::Key_E&&keyEvent->isAutoRepeat()==true)
        {
            return true;
        }
        if (keyEvent->key() == Qt::Key_W&&keyEvent->isAutoRepeat()==true)
        {
            return true;
        }
        if (keyEvent->key() == Qt::Key_Q&&keyEvent->isAutoRepeat()==true)
        {
            return true;
        }
        if (keyEvent->key() == Qt::Key_R&&keyEvent->isAutoRepeat()==true)
        {
            return true;
        }
    }
    return false;
};


void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug()<<"Enter Press";

    qDebug()<<event->key();

    if(event->isAutoRepeat()==false){
        QTextStream data(&file);
        switch (event->key()) {
        case Qt::Key_Q:
            tone->Q_Key.TenutoChange(Is_tenuto_space);
            tone->Q_KeyPlay(tim->elapsed());
            if(Is_record) data<<tone->Q_Key;
            break;
        case Qt::Key_W:
            tone->W_Key.TenutoChange(Is_tenuto_space);
            tone->W_KeyPlay(tim->elapsed());
            if(Is_record) data<<tone->W_Key;
            break;
        case Qt::Key_E:
            tone->E_Key.TenutoChange(Is_tenuto_space);
            tone->E_KeyPlay(tim->elapsed());
            if(Is_record) data<<tone->E_Key;
            break;
        case Qt::Key_R:
            tone->R_Key.TenutoChange(Is_tenuto_space);
            tone->R_KeyPlay(tim->elapsed());
            if(Is_record) data<<tone->R_Key;
            break;
        case Qt::Key_T:
            tone->T_Key.TenutoChange(Is_tenuto_space);
            tone->T_KeyPlay(tim->elapsed());
            if(Is_record) data<<tone->T_Key;
            break;
        case Qt::Key_Y:
            tone->Y_Key.TenutoChange(Is_tenuto_space);
            tone->Y_KeyPlay(tim->elapsed());
            if(Is_record) data<<tone->Y_Key;
            break;
        case Qt::Key_Shift:
            switch (tone->Level) {
            case -4:
                break;
            case -3:
                break;
            case -2:
                break;
            case -1:
                break;
            case 0:
                tone=&cc;
                tone->Level=cc.Level;
//                qDebug()<<tone->Level<<" "<<cc.Level;
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            }
            break;
        case Qt::Key_Control:
            switch (tone->Level) {
            case -4:
                break;
            case -3:
                break;
            case -2:
                break;
            case -1:
                break;
            case 0:
//                qDebug()<<tone->Level<<" "<<cc.Level;
                break;
            case 1:
                tone=&c;
                tone->Level=c.Level;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            }
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


//***********************************************//
//****************** 音频处理 ********************//
//***********************************************//

//** 延音改变 **//
void MainWindow::TenutoChange(void){
    if(Is_tenuto_space==0) Is_tenuto_space=1;
    else Is_tenuto_space=0;
};

//** 录制音频 **//
void MainWindow::Record(QString filename){
    tim=new QElapsedTimer;
    tim->start();
    Is_record=1;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly);
};
void MainWindow::StopRecord(){
    Is_record=0;
    file.close();
};

//** 改变音调 **//

MainWindow::~MainWindow()
{
    delete ui;
}

