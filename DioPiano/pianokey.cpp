#include "pianokey.h"
#include <QSound>
#include <QDebug>

//PianoKey::PianoKey(QWidget *parent) : QWidget(parent)
//{
//}

PianoKey::PianoKey()
{
//    timer=new QTimer(this);
//    connect(timer,&QTimer::timeout,[=](){
//        Is_LongPress=1;
//        V_short->play();
//        timer->stop();
//        qDebug()<<"connect";
//    });
}

int PianoKey::SetVoice(int file_num){
    num.setNum(file_num);
    filename=":/voice/"+num+".wav";
    filename_=":/voice/"+num+"_.wav";
    V_long = new QSound(filename);
    V_short= new QSound(filename_);
    return file_num;
};

void PianoKey::VoicePlay(void){
    qDebug()<<Is_tenuto<<" key";
    if(!Is_tenuto) {V_short->play();qDebug()<<"short";}
    else {V_long->play();qDebug()<<"long";}
    qDebug()<<"fin";
};



void PianoKey::TenutoChange(bool te){
    Is_tenuto=te;
};

bool PianoKey::GetTenuto(void){
    return Is_tenuto;
};

void PianoKey::RecordTime(int st){
    Pr_time=st;
};

QTextStream& operator<<(QTextStream& stream,PianoKey& Key){
    stream<<Key.Pr_time<<" "<<Key.Is_tenuto<<" "<<Key.num<<endl;
    return stream;
};


//void PianoKey::VoiceStop(int ms){
//    QTimer *delay=new QTimer(this);
//    delay->start(ms);
//    connect(delay,&QTimer::timeout,[=](){
//        V_long->stop();
//        delay->stop();
//    });
//};

//void PianoKey::PressmodeChange(void){
//    if(Is_LongPress==1) Is_LongPress=0;
//    else Is_LongPress=1;
//};

//bool PianoKey::GetPressmode(void){
//    return Is_LongPress;
//};

