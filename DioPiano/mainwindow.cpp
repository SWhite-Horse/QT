#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pianokey.h"
#include <QTimer>
#include <QKeyEvent>
#include <QTextStream>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tone=&c; //**初始化为C大调
    setFocusPolicy(Qt::StrongFocus); //** 获得焦点
    this->installEventFilter(this);

    //设定窗口大小
    this->setFixedSize(1134,500);
    //设置Title图标
    this->setWindowIcon(QIcon(":/image/11.png"));
    //设置Title
    this->setWindowTitle("DioPiano");

    //*******************//
    //** 菜单栏功能实现区 **//
    //*******************//

    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    connect(ui->actionstart,&QAction::triggered,[=](){
        QString filename=QInputDialog::getText(NULL, "Record","请输入文件名", QLineEdit::Normal);
        Record(filename);
    });

    connect(ui->actionstop,&QAction::triggered,[=](){
        StopRecord();
        //** 可以加一个是否播放的按钮
    });

    connect(ui->actionerror,&QAction::triggered,[=](){
        QMessageBox::critical(this,"警告","这个程序没有bug!!没有~");
    });

//    connect(ui->actionplay,&QAction::triggered,[=](){
////        //** 记得修改文件路径
////        QString filename=QFileDialog:: getOpenFileName(this,"打开音乐","/");
//        Replay("myfile.txt");
//        //** 还要考虑怎么停止播放
//    });


//    //** 帮助按钮的实现 **//

//    QStringList list;
//    list<<"○ 由于键盘限制，程序仅使用了从 ~ 到 Backspace，和它的下一行作为演奏琴键"
//        <<"○ 这包括了4个八度中的28个键，以C大调为例，其中 U 键为中央 1 "
//        <<"○ 需要注意的是，U 所在八度上面的八度，即从 7 键开始的八度，是U高八度"
//        <<"○ U 左侧的八度是低八度，Tab键上侧的八度是Tab键所在八度的低八度"
//        <<"○ 应用提供了变调功能来延展键盘，其中Shift为升调，Ctrl为降调"
//        <<"○ 钢琴键与键盘的对应关系其实可以通过应用中按键动画的响应来判断"
//        <<"○ 应用提供短音和长音（延音）两种方式，空格键切换,若切换失败,请点击键盘一次之后再次切换"
//        <<"○ 应用提供了录制功能"
//        <<"○ 使用中如有bug出现，请点击 帮助->报错 查看原因，找不到解决办法就算了吧"
//        <<"○ 宁就是东大贝多芬，祝宁使用愉快！！！！！！！！";
//    connect(ui->actionfresh,&QAction::triggered,[=](){
//    });

    //**************//
    //** 按键初始化 **//
    //**************//

    int j=1;
    for (int i=0;i<88;i++) {
        if(i==0||i==2||(i-3)%12==0||(i-5)%12==0||(i-7)%12==0||(i-8)%12==0||(i-10)%12==0||(i-12)%12==0||(i-14)%12==0||i==87)
        {
            TKey[i].SetImage(2);
            TKey[i].setParent(this);
            TKey[i].move(21*j,44);
            TKey[i].SetVoice(i+1);
            j++;
        }
    };
    j=1;
    for (int i=0;i<88;i++) {
        if(i==0||i==2||(i-3)%12==0||(i-5)%12==0||(i-7)%12==0||(i-8)%12==0||(i-10)%12==0||(i-12)%12==0||(i-14)%12==0||i==87)
            j++;
        else {
            TKey[i].SetImage(1);
            TKey[i].setParent(this);
            TKey[i].move(21*j-8.4,44);
            TKey[i].SetVoice(i+1);
        }
    };
}

//** 绘制背景 **//
void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/backGround.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
};





//***********************************************//
//***************** Press处理 ********************//
//***********************************************//

bool MainWindow::eventFilter(QObject * obj,QEvent * event){

    if(event->type() == QEvent::KeyPress)
    {

        QTextStream data(&file);
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        //** 改变延音效果 **//
        if (keyEvent->key() == Qt::Key_Space&&keyEvent->isAutoRepeat()==false)
        {
            TenutoChange();
            return true;
        }

        //** Tab 键单独处理 **//
        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==false)
        {
            tone->Tab_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Tab_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Tab_Key,tim->elapsed());
                data<<tone->Tab_Key;
            }
            else
                tone->Key_Play(tone->Tab_Key);
            return true;
        }
    }
    if(event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Tab&&keyEvent->isAutoRepeat()==false)
        {
            TKey[tone->Tab_Key.GetNum()-1].Release_Image();
            return true;
        }
        return false;
    }
    return QMainWindow::eventFilter(obj,event);
};

void MainWindow::keyPressEvent(QKeyEvent *event){
//    qDebug()<<"Enter Press";
    if(event->isAutoRepeat()==false){
        QTextStream data(&file);
        switch (event->key()) {
        case Qt::Key_QuoteLeft:
            tone->QuoteLeft_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->QuoteLeft_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->QuoteLeft_Key,tim->elapsed());
                data<<tone->QuoteLeft_Key;
            }
            else
                tone->Key_Play(tone->QuoteLeft_Key);
            break;
        case Qt::Key_1:
            tone->Key1.TenutoChange(Is_tenuto_space);
            TKey[tone->Key1.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key1,tim->elapsed());
                data<<tone->Key1;
            }
            else
                tone->Key_Play(tone->Key1);
            break;
        case Qt::Key_2:
            tone->Key2.TenutoChange(Is_tenuto_space);
            TKey[tone->Key2.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key2,tim->elapsed());
                data<<tone->Key2;
            }
            else
                tone->Key_Play(tone->Key2);
            break;
        case Qt::Key_3:
            tone->Key3.TenutoChange(Is_tenuto_space);
            TKey[tone->Key3.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key3,tim->elapsed());
                data<<tone->Key3;
            }
            else
                tone->Key_Play(tone->Key3);
            break;
        case Qt::Key_4:
            tone->Key4.TenutoChange(Is_tenuto_space);
            TKey[tone->Key4.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key4,tim->elapsed());
                data<<tone->Key4;
            }
            else
                tone->Key_Play(tone->Key4);
            break;
        case Qt::Key_5:
            tone->Key5.TenutoChange(Is_tenuto_space);
            TKey[tone->Key5.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key5,tim->elapsed());
                data<<tone->Key5;
            }
            else
                tone->Key_Play(tone->Key5);
            break;
        case Qt::Key_6:
            tone->Key6.TenutoChange(Is_tenuto_space);
            TKey[tone->Key6.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key6,tim->elapsed());
                data<<tone->Key6;
            }
            else
                tone->Key_Play(tone->Key6);
            break;
        case Qt::Key_7:
            tone->Key7.TenutoChange(Is_tenuto_space);
            TKey[tone->Key7.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key7,tim->elapsed());
                data<<tone->Key7;
            }
            else
                tone->Key_Play(tone->Key7);
            break;
        case Qt::Key_8:
            tone->Key8.TenutoChange(Is_tenuto_space);
            TKey[tone->Key8.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key8,tim->elapsed());
                data<<tone->Key8;
            }
            else
                tone->Key_Play(tone->Key8);
            break;
        case Qt::Key_9:
            tone->Key9.TenutoChange(Is_tenuto_space);
            TKey[tone->Key9.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key9,tim->elapsed());
                data<<tone->Key9;
            }
            else
                tone->Key_Play(tone->Key9);
            break;
        case Qt::Key_0:
            tone->Key0.TenutoChange(Is_tenuto_space);
            TKey[tone->Key0.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Key0,tim->elapsed());
                data<<tone->Key0;
            }
            else
                tone->Key_Play(tone->Key0);
            break;
        case Qt::Key_Minus:
            tone->Minus_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Minus_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Minus_Key,tim->elapsed());
                data<<tone->Minus_Key;
            }
            else
                tone->Key_Play(tone->Minus_Key);
            break;
        case Qt::Key_Equal:
            tone->Equal_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Equal_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Equal_Key,tim->elapsed());
                data<<tone->Equal_Key;
            }
            else
                tone->Key_Play(tone->Equal_Key);
            break;
        case Qt::Key_Backspace:
            tone->Backspace_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Backspace_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Backspace_Key,tim->elapsed());
                data<<tone->Backspace_Key;
            }
            else
                tone->Key_Play(tone->Backspace_Key);
            break;
        case Qt::Key_Q:
            tone->Q_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Q_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Q_Key,tim->elapsed());
                data<<tone->Q_Key;
            }
            else
                tone->Key_Play(tone->Q_Key);
            break;
        case Qt::Key_W:
            tone->W_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->W_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->W_Key,tim->elapsed());
                data<<tone->W_Key;
            }
            else
                tone->Key_Play(tone->W_Key);
            break;
        case Qt::Key_E:
            tone->E_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->E_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->E_Key,tim->elapsed());
                data<<tone->E_Key;
            }
            else
                tone->Key_Play(tone->E_Key);
            break;
        case Qt::Key_R:
            tone->R_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->R_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->R_Key,tim->elapsed());
                data<<tone->R_Key;
            }
            else
                tone->Key_Play(tone->R_Key);
            break;
        case Qt::Key_T:
            tone->T_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->T_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->T_Key,tim->elapsed());
                data<<tone->T_Key;
            }
            else
                tone->Key_Play(tone->T_Key);
            break;
        case Qt::Key_Y:
            tone->Y_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Y_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Y_Key,tim->elapsed());
                data<<tone->Y_Key;
            }
            else
                tone->Key_Play(tone->Y_Key);
            break;
        case Qt::Key_U:
            tone->U_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->U_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->U_Key,tim->elapsed());
                data<<tone->U_Key;
            }
            else
                tone->Key_Play(tone->U_Key);
            break;
        case Qt::Key_I:
            tone->I_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->I_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->I_Key,tim->elapsed());
                data<<tone->I_Key;
            }
            else
                tone->Key_Play(tone->I_Key);
            break;
        case Qt::Key_O:
            tone->O_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->O_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->O_Key,tim->elapsed());
                data<<tone->O_Key;
            }
            else
                tone->Key_Play(tone->O_Key);
            break;
        case Qt::Key_P:
            tone->P_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->P_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->P_Key,tim->elapsed());
                data<<tone->P_Key;
            }
            else
                tone->Key_Play(tone->P_Key);
            break;
        case Qt::Key_BracketLeft:
            tone->BracketLeft_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->BracketLeft_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->BracketLeft_Key,tim->elapsed());
                data<<tone->BracketLeft_Key;
            }
            else
                tone->Key_Play(tone->BracketLeft_Key);
            break;
        case Qt::Key_BracketRight:
            tone->BracketRight_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->BracketRight_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->BracketRight_Key,tim->elapsed());
                data<<tone->BracketRight_Key;
            }
            else
                tone->Key_Play(tone->BracketRight_Key);
            break;
        case Qt::Key_Backslash:
            tone->Backslash_Key.TenutoChange(Is_tenuto_space);
            TKey[tone->Backslash_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                tone->Key_Play(tone->Backslash_Key,tim->elapsed());
                data<<tone->Backslash_Key;
            }
            else
                tone->Key_Play(tone->Backslash_Key);
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
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->isAutoRepeat()==false){
        switch (event->key()) {
        case Qt::Key_QuoteLeft:
            TKey[tone->QuoteLeft_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_1:
            TKey[tone->Key1.GetNum()-1].Release_Image();
            break;
        case Qt::Key_2:
            TKey[tone->Key2.GetNum()-1].Release_Image();
            break;
        case Qt::Key_3:
            TKey[tone->Key3.GetNum()-1].Release_Image();
            break;
        case Qt::Key_4:
            TKey[tone->Key4.GetNum()-1].Release_Image();
            break;
        case Qt::Key_5:
            TKey[tone->Key5.GetNum()-1].Release_Image();
            break;
        case Qt::Key_6:
            TKey[tone->Key6.GetNum()-1].Release_Image();
            break;
        case Qt::Key_7:
            TKey[tone->Key7.GetNum()-1].Release_Image();
            break;
        case Qt::Key_8:
            TKey[tone->Key8.GetNum()-1].Release_Image();
            break;
        case Qt::Key_9:
            TKey[tone->Key9.GetNum()-1].Release_Image();
            break;
        case Qt::Key_0:
            TKey[tone->Key0.GetNum()-1].Release_Image();
            break;
        case Qt::Key_Minus:
            TKey[tone->Minus_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_Equal:
            TKey[tone->Equal_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_Backspace:
            TKey[tone->Backspace_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_Q:
            TKey[tone->Q_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_W:
            TKey[tone->W_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_E:
            TKey[tone->E_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_R:
            TKey[tone->R_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_T:
            TKey[tone->T_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_Y:
            TKey[tone->Y_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_U:
            TKey[tone->U_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_I:
            TKey[tone->I_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_O:
            TKey[tone->O_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_P:
            TKey[tone->P_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_BracketLeft:
            TKey[tone->BracketLeft_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_BracketRight:
            TKey[tone->BracketRight_Key.GetNum()-1].Release_Image();
            break;
        case Qt::Key_Backslash:
            TKey[tone->Backslash_Key.GetNum()-1].Release_Image();
            break;
        }
    }
};


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
    filename=filename+".txt";
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

void MainWindow::Replay(QString filename){
    PianoKey play;
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream datacome(&file);
    tim=new QElapsedTimer;

//    QString name;
    datacome>>play;
    tim->start();
    int n=play.GetNum()-1;
    qDebug()<<play.GetTime()<<" "<<tim->elapsed();
    while(1){
//        name=QString("/voice/%1.wav").arg(play.GetNum());
        if(datacome.atEnd())
           break;
        if(play.GetTime()!=0&&play.GetTime()==tim->elapsed()){
           qDebug()<<"enter play";
           TKey[play.GetNum()-1].TenutoChange(play.GetTenuto());
           TKey[play.GetNum()-1].VoicePlay();
//           if(play.GetTenuto())
//           play.SetVoice(play.GetNum());
//           play.VoicePlay();

           qDebug()<<TKey[n].GetV_S();
           datacome>>play;
        }
    }

};


//** 改变音调 **//

MainWindow::~MainWindow()
{
    delete ui;
}

