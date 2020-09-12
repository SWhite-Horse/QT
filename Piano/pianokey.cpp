#include "pianokey.h"
#include <QSound>
#include <QDebug>
PianoKey::PianoKey()
{

}

bool PianoKey::SetVoice(int file_num){
    QString num;
    num.setNum(file_num);
    QString filename=":/voice/"+num+".wav";
    Vp = new QSound("filename");
    return 0;
};

void PianoKey::VoicePlay(void){
    Vp->play();
    qDebug()<<"Success！";
};

void PianoKey::VoiceStop(void){
    Vp->stop();
};
