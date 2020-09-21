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

    //*******************//
    //** 窗口初始化区 **//
    //*******************//

    ui->setupUi(this);

    tone=&c; //**初始化为C大调
    pix4.load(":/image/t5.png");//** 音调显示初始化
    pix4=pix4.scaled(pix4.width()*0.5,pix4.height()*0.5);

    setFocusPolicy(Qt::StrongFocus); //** 获得焦点

    this->installEventFilter(this);
    this->setFixedSize(1134,500);//**设定窗口大小
    this->setWindowIcon(QIcon(":/image/11.png"));//**设置Title图标
    this->setWindowTitle("DioPiano");//**设置Title


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

    connect(ui->actionplay,&QAction::triggered,[=](){
//        //** 记得修改文件路径
//        QString filename=QFileDialog:: getOpenFileName(this,"打开音乐","/");
        Replay("myfile.txt");
        //** 还要考虑怎么停止播放
    });


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
    connect(ui->actionfresh,&QAction::triggered,[=](){

    });

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
            TKey[i].setVoice(i+1);
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
            TKey[i].setVoice(i+1);
        }
    };
}

//***********************************************//
//************** 画面绘制，变调动画 ****************//
//***********************************************//

void MainWindow::Drawmap(int tone){
    QString n;
    n.setNum(tone);
    pix4.load(":/image/t"+n+".png");
    pix4=pix4.scaled(pix4.width()*0.5,pix4.height()*0.5);
    update();
};


void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);

    pix1.load(":/image/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    pix2.load(":/image/img.png");
    pix2=pix2.scaled(pix2.width()*1.5,pix2.height()*1.5);
    painter.drawPixmap(0,this->height()-pix2.height(),pix2);

    pix3.load(":/image/img2.png");
    pix3=pix3.scaled(pix3.width()*0.5,pix3.height()*0.5);
    painter.drawPixmap(this->width()-pix3.width(),this->height()-pix3.height(),pix3);

    painter.drawPixmap((this->width()-pix4.width())*0.5,this->height()-pix4.height(),pix4);

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
            TKey[tone->Tab_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Tab_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Tab_Key.GetNum()-1].VoicePlay();
                TKey[tone->Tab_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Tab_Key.GetNum()-1];
            }
            else
                TKey[tone->Tab_Key.GetNum()-1].VoicePlay();
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
            TKey[tone->QuoteLeft_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->QuoteLeft_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->QuoteLeft_Key.GetNum()-1].VoicePlay();
                TKey[tone->QuoteLeft_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->QuoteLeft_Key.GetNum()-1];
            }
            else
                TKey[tone->QuoteLeft_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_1:
            TKey[tone->Key1.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key1.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key1.GetNum()-1].VoicePlay();
                TKey[tone->Key1.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key1.GetNum()-1];
            }
            else
                TKey[tone->Key1.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_2:
            TKey[tone->Key2.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key2.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key2.GetNum()-1].VoicePlay();
                TKey[tone->Key2.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key2.GetNum()-1];
            }
            else
                TKey[tone->Key2.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_3:
            TKey[tone->Key3.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key3.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key3.GetNum()-1].VoicePlay();
                TKey[tone->Key2.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key3.GetNum()-1];
            }
            else
                TKey[tone->Key3.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_4:
            TKey[tone->Key4.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key4.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key4.GetNum()-1].VoicePlay();
                TKey[tone->Key3.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key4.GetNum()-1];
            }
            else
                TKey[tone->Key4.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_5:
            TKey[tone->Key5.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key5.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key5.GetNum()-1].VoicePlay();
                TKey[tone->Key5.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key5.GetNum()-1];
            }
            else
                TKey[tone->Key5.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_6:
            TKey[tone->Key6.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key6.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key6.GetNum()-1].VoicePlay();
                TKey[tone->Key6.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key6.GetNum()-1];
            }
            else
                TKey[tone->Key6.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_7:
            TKey[tone->Key7.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key7.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key7.GetNum()-1].VoicePlay();
                TKey[tone->Key7.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key7.GetNum()-1];
            }
            else
                TKey[tone->Key7.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_8:
            TKey[tone->Key8.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key8.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key8.GetNum()-1].VoicePlay();
                TKey[tone->Key8.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key8.GetNum()-1];
            }
            else
                TKey[tone->Key8.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_9:
            TKey[tone->Key9.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key9.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key9.GetNum()-1].VoicePlay();
                TKey[tone->Key9.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key9.GetNum()-1];
            }
            else
                TKey[tone->Key9.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_0:
            TKey[tone->Key0.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Key0.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Key0.GetNum()-1].VoicePlay();
                TKey[tone->Key0.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Key0.GetNum()-1];
            }
            else
                TKey[tone->Key0.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_Minus:
            TKey[tone->Minus_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Minus_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Minus_Key.GetNum()-1].VoicePlay();
                TKey[tone->Minus_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Minus_Key.GetNum()-1];
            }
            else
                TKey[tone->Minus_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_Equal:
            TKey[tone->Equal_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Equal_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Equal_Key.GetNum()-1].VoicePlay();
                TKey[tone->Equal_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Equal_Key.GetNum()-1];
            }
            else
                TKey[tone->Equal_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_Backspace:
            TKey[tone->Backspace_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Backspace_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Backspace_Key.GetNum()-1].VoicePlay();
                TKey[tone->Backspace_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Backspace_Key.GetNum()-1];
            }
            else
                TKey[tone->Backspace_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_Q:
            TKey[tone->Q_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Q_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Q_Key.GetNum()-1].VoicePlay();
                TKey[tone->Q_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Q_Key.GetNum()-1];
            }
            else
                TKey[tone->Q_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_W:
            TKey[tone->W_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->W_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->W_Key.GetNum()-1].VoicePlay();
                TKey[tone->W_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->W_Key.GetNum()-1];
            }
            else
                TKey[tone->W_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_E:
            TKey[tone->E_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->E_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->E_Key.GetNum()-1].VoicePlay();
                TKey[tone->E_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->E_Key.GetNum()-1];
            }
            else
                TKey[tone->E_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_R:
            TKey[tone->R_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->R_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->R_Key.GetNum()-1].VoicePlay();
                TKey[tone->R_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->R_Key.GetNum()-1];
            }
            else
                TKey[tone->R_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_T:
            TKey[tone->T_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->T_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->T_Key.GetNum()-1].VoicePlay();
                TKey[tone->T_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->T_Key.GetNum()-1];
            }
            else
                TKey[tone->T_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_Y:
            TKey[tone->Y_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Y_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Y_Key.GetNum()-1].VoicePlay();
                TKey[tone->Y_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Y_Key.GetNum()-1];
            }
            else
                TKey[tone->Y_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_U:
            TKey[tone->U_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->U_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->U_Key.GetNum()-1].VoicePlay();
                TKey[tone->U_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->U_Key.GetNum()-1];
            }
            else
                TKey[tone->U_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_I:
            TKey[tone->I_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->I_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->I_Key.GetNum()-1].VoicePlay();
                TKey[tone->I_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->I_Key.GetNum()-1];
            }
            else
                TKey[tone->I_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_O:
            TKey[tone->O_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->O_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->O_Key.GetNum()-1].VoicePlay();
                TKey[tone->O_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->O_Key.GetNum()-1];
            }
            else
                TKey[tone->O_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_P:
            TKey[tone->P_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->P_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->P_Key.GetNum()-1].VoicePlay();
                TKey[tone->P_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->P_Key.GetNum()-1];
            }
            else
                TKey[tone->P_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_BracketLeft:
            TKey[tone->BracketLeft_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->BracketLeft_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->BracketLeft_Key.GetNum()-1].VoicePlay();
                TKey[tone->BracketLeft_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->BracketLeft_Key.GetNum()-1];
            }
            else
                TKey[tone->BracketLeft_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_BracketRight:
            TKey[tone->BracketRight_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->BracketRight_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->BracketRight_Key.GetNum()-1].VoicePlay();
                TKey[tone->BracketRight_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->BracketRight_Key.GetNum()-1];
            }
            else
                TKey[tone->BracketRight_Key.GetNum()-1].VoicePlay();
            break;
        case Qt::Key_Backslash:
            TKey[tone->Backslash_Key.GetNum()-1].TenutoChange(Is_tenuto_space);
            TKey[tone->Backslash_Key.GetNum()-1].Press_Image();
            if(Is_record) {
                TKey[tone->Backslash_Key.GetNum()-1].VoicePlay();
                TKey[tone->Backslash_Key.GetNum()-1].RecordTime(tim->elapsed());
                data<<TKey[tone->Backslash_Key.GetNum()-1];
            }
            else
                TKey[tone->Backslash_Key.GetNum()-1].VoicePlay();
            break;

        case Qt::Key_Shift:
            Drawmap((tone->Level+5)%14+1);
            switch (tone->Level) {
            case -5:
                tone=&a;
                tone->Level=a.Level;
                break;
            case -4:
                tone=&bb;
                tone->Level=bb.Level;
                break;
            case -3:
                tone=&b;
                tone->Level=b.Level;
                break;
            case -2:
                tone=&cb;
                tone->Level=cb.Level;
                break;
            case -1:
                tone=&c;
                tone->Level=c.Level;
                break;
            case 0:
                tone=&cc;
                tone->Level=cc.Level;

                break;
            case 1:
                tone=&db;
                tone->Level=db.Level;
                break;
            case 2:
                tone=&d;
                tone->Level=d.Level;
                break;
            case 3:
                tone=&eb;
                tone->Level=eb.Level;
                break;
            case 4:
                tone=&e;
                tone->Level=e.Level;
                break;
            case 5:
                tone=&f;
                tone->Level=f.Level;
                break;
            case 6:
                tone=&ff;
                tone->Level=ff.Level;
                break;
            case 7:
                tone=&gb;
                tone->Level=gb.Level;
                break;
            case 8:
                tone=&g;
                tone->Level=g.Level;
                break;
            case 9:
                tone=&ab;
                tone->Level=ab.Level;
                break;
            }
            break;
        case Qt::Key_Control:
            Drawmap((tone->Level+5)==0?14:((tone->Level+5)-1));
            switch (tone->Level) {
            case -5:
                tone=&g;
                tone->Level=g.Level;
                break;
            case -4:
                tone=&ab;
                tone->Level=ab.Level;
                break;
            case -3:
                tone=&a;
                tone->Level=a.Level;
                break;
            case -2:
                tone=&bb;
                tone->Level=bb.Level;
                break;
            case -1:
                tone=&b;
                tone->Level=b.Level;
                break;
            case 0:
                tone=&cb;
                tone->Level=cb.Level;
                break;
            case 1:
                tone=&c;
                tone->Level=c.Level;
                break;
            case 2:
                tone=&cc;
                tone->Level=cc.Level;
                break;
            case 3:
                tone=&db;
                tone->Level=db.Level;
                break;
            case 4:
                tone=&d;
                tone->Level=d.Level;
                break;
            case 5:
                tone=&eb;
                tone->Level=eb.Level;
                break;
            case 6:
                tone=&e;
                tone->Level=e.Level;
                break;
            case 7:
                tone=&f;
                tone->Level=f.Level;
                break;
            case 8:
                tone=&ff;
                tone->Level=ff.Level;
                break;
            case 9:
                tone=&gb;
                tone->Level=gb.Level;
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
    qDebug()<<play.GetTime()<<" "<<tim->elapsed();
    while(1){
        if(play.GetNum()==0)
           break;
        if(play.GetTime()==tim->elapsed()){
           qDebug()<<"enter play"<<play.GetNum();
           TKey[play.GetNum()-1].TenutoChange(play.GetTenuto());
           TKey[play.GetNum()-1].VoicePlay();
           datacome>>play;
        }
    }

};


//** 改变音调 **//

MainWindow::~MainWindow()
{
    delete ui;
}

