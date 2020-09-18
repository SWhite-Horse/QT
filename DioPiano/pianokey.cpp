#include "pianokey.h"
#include <QSound>
#include <QDebug>

//PianoKey::PianoKey(QWidget *parent) : QWidget(parent)
//{
//}

PianoKey::PianoKey()
{

}

int PianoKey::SetImage(int BorW){
    QString n;
    n.setNum(BorW);
    QString path=":/image/"+n;
    this->Path=path;
    pix.load(path+"1.png");
    //设置图片固定大小
    this->setFixedSize(pix.width()*0.35,pix.height()*0.35);
    //设置不规则图片样式（边界零像素）
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置琴键图案
    this->setIcon(pix);
    //设置琴键大小
    this->setIconSize(QSize(pix.width()*0.35,pix.height()*0.35));
    return BorW;
};

void PianoKey::Press_Image(){
    pix.load(Path+"2.png");
    this->setFixedSize(pix.width()*0.35,pix.height()*0.35);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width()*0.35,pix.height()*0.35));
};
void PianoKey::Release_Image(){
    pix.load(Path+"1.png");
    this->setFixedSize(pix.width()*0.35,pix.height()*0.35);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width()*0.35,pix.height()*0.35));
};

int PianoKey::SetVoice(int file_num){
    num=file_num;
    QString n;
    n.setNum(num);
    filename=":/voice/"+n+".wav";
    filename_=":/voice/"+n+"_.wav";
    V_long = new QSound(filename);
    V_short= new QSound(filename_);
    return file_num;
};

void PianoKey::VoicePlay(void){
    qDebug()<<"enter play V";
    if(!Is_tenuto) {
        V_short->play();
        qDebug()<<"enter play short";
    }
    else {V_long->play();
              qDebug()<<"enter play long";}
};



void PianoKey::TenutoChange(int te){
    Is_tenuto=te;
};

int PianoKey::GetTenuto(void){
    return Is_tenuto;
};

int PianoKey::GetTime(void){
    return Pr_time;
};

int PianoKey::GetNum(void){
    return num;
};

void PianoKey::RecordTime(int st){
    Pr_time=st;
};

bool PianoKey::GetV_S(){
    return this->V_short->isFinished();
};
QTextStream& operator<<(QTextStream& stream,PianoKey& Key){
    stream<<Key.Pr_time<<" "<<Key.Is_tenuto<<" "<<Key.num<<endl;
    return stream;
};
QTextStream& operator>>(QTextStream& stream,PianoKey& Key){
    stream>>Key.Pr_time>>Key.Is_tenuto>>Key.num;
    qDebug()<<Key.Pr_time<<Key.Is_tenuto<<Key.num;
//    if(Key.Pr_time!=0) Key.SetVoice(Key.num);
    return stream;
};

