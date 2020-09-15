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
            return true;
        }
//        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==true)
//        {
//            return true;
//        }
        //** Tab 键单独处理 **//
        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==false)
        {
            tone->Tab_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Tab_Key,tim->elapsed());
            if(Is_record) data<<tone->Tab_Key;
            return true;
        }
    }
    return QMainWindow::eventFilter(obj,event);
};


bool MainWindow::event(QEvent * ev){
//    if(ev->type() == QEvent::KeyPress){
//        QKeyEvent *event = static_cast<QKeyEvent *>(ev);
//        QTextStream data(&file);

//        if(event->isAutoRepeat()==true){
//            switch (event->key()) {
//            case Qt::Key_Q:
//                return true;
//            case Qt::Key_W:
//                return true;
//            case Qt::Key_E:
//                return true;
//            case Qt::Key_R:
//                return true;
//            case Qt::Key_T:
//                return true;
//            case Qt::Key_Y:
//                return true;
//            case Qt::Key_U:
//                return true;
//            case Qt::Key_I:
//                return true;
//            case Qt::Key_O:
//                return true;
//            case Qt::Key_P:
//                return true;
//            case Qt::Key_BracketLeft:
//                return true;
//            case Qt::Key_BracketRight:
//                return true;
//            case Qt::Key_Backslash:
//                return true;
//            }
//        }
//    }
    return QMainWindow::event(ev);
};


void MainWindow::keyPressEvent(QKeyEvent *event){
//    qDebug()<<"Enter Press";
//    qDebug()<<event->key();

    if(event->isAutoRepeat()==false){
        QTextStream data(&file);
        switch (event->key()) {
        case 96:
            tone->AsciiTilde_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->AsciiTilde_Key,tim->elapsed());
            if(Is_record) data<<tone->AsciiTilde_Key;
            break;
//        case Qt::Key_AsciiTilde: //** 在笔记本上，Qt中96，是~，但是标注的是126，也就是AsciiTilde
//            tone->AsciiTilde_Key.TenutoChange(Is_tenuto_space);
//            tone->AsciiTilde_KeyPlay(tim->elapsed());
//            if(Is_record) data<<tone->AsciiTilde_Key;
//            break;
        case Qt::Key_1:
            tone->Key1.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key1,tim->elapsed());
            if(Is_record) data<<tone->Key1;
            break;
        case Qt::Key_2:
            tone->Key2.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key2,tim->elapsed());
            if(Is_record) data<<tone->Key2;
            break;
        case Qt::Key_3:
            tone->Key3.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key3,tim->elapsed());
            if(Is_record) data<<tone->Key3;
            break;
        case Qt::Key_4:
            tone->Key4.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key4,tim->elapsed());
            if(Is_record) data<<tone->Key4;
            break;
        case Qt::Key_5:
            tone->Key5.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key5,tim->elapsed());
            if(Is_record) data<<tone->Key5;
            break;
        case Qt::Key_6:
            tone->Key6.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key6,tim->elapsed());
            if(Is_record) data<<tone->Key6;
            break;
        case Qt::Key_7:
            tone->Key7.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key7,tim->elapsed());
            if(Is_record) data<<tone->Key7;
            break;
        case Qt::Key_8:
            tone->Key8.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key8,tim->elapsed());
            if(Is_record) data<<tone->Key8;
            break;
        case Qt::Key_9:
            tone->Key9.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key9,tim->elapsed());
            if(Is_record) data<<tone->Key9;
            break;
        case Qt::Key_0:
            tone->Key0.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Key6,tim->elapsed());
            if(Is_record) data<<tone->Key0;
            break;
        case Qt::Key_Minus:
            tone->Minus_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Minus_Key,tim->elapsed());
            if(Is_record) data<<tone->Minus_Key;
            break;
        case Qt::Key_Equal:
            tone->Equal_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Equal_Key,tim->elapsed());
            if(Is_record) data<<tone->Equal_Key;
            break;
        case Qt::Key_Backspace:
            tone->Backspace_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Backspace_Key,tim->elapsed());
            if(Is_record) data<<tone->Backspace_Key;
            break;
        case Qt::Key_Q:
            tone->Q_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Q_Key,tim->elapsed());
            if(Is_record) data<<tone->Q_Key;
            break;
        case Qt::Key_W:
            tone->W_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->W_Key,tim->elapsed());
            if(Is_record) data<<tone->W_Key;
            break;
        case Qt::Key_E:
            tone->E_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->E_Key,tim->elapsed());
            if(Is_record) data<<tone->E_Key;
            break;
        case Qt::Key_R:
            tone->R_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->R_Key,tim->elapsed());
            if(Is_record) data<<tone->R_Key;
            break;
        case Qt::Key_T:
            tone->T_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->T_Key,tim->elapsed());
            if(Is_record) data<<tone->T_Key;
            break;
        case Qt::Key_Y:
            tone->Y_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Y_Key,tim->elapsed());
            if(Is_record) data<<tone->Y_Key;
            break;
        case Qt::Key_U:
            tone->U_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->U_Key,tim->elapsed());
            if(Is_record) data<<tone->U_Key;
            break;
        case Qt::Key_I:
            tone->I_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->I_Key,tim->elapsed());
            if(Is_record) data<<tone->I_Key;
            break;
        case Qt::Key_O:
            tone->O_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->O_Key,tim->elapsed());
            if(Is_record) data<<tone->O_Key;
            break;
        case Qt::Key_P:
            tone->P_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->P_Key,tim->elapsed());
            if(Is_record) data<<tone->P_Key;
            break;
        case Qt::Key_BracketLeft:
            tone->BracketLeft_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->BracketLeft_Key,tim->elapsed());
            if(Is_record) data<<tone->BracketLeft_Key;
            break;
        case Qt::Key_BracketRight:
            tone->BracketRight_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->BracketRight_Key,tim->elapsed());
            if(Is_record) data<<tone->BracketRight_Key;
            break;
        case Qt::Key_Backslash:
            tone->Backslash_Key.TenutoChange(Is_tenuto_space);
            tone->Key_Play(tone->Backslash_Key,tim->elapsed());
            if(Is_record) data<<tone->Backslash_Key;
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

