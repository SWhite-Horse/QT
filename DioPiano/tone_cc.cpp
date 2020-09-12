#include "tone_cc.h"
#include <QDebug>

Tone_Cc::Tone_Cc()
{
    Tab_Key.SetVoice(28);
    Q_Key.SetVoice(30);
    W_Key.SetVoice(32);
    E_Key.SetVoice(31);
    R_Key.SetVoice(35);
    T_Key.SetVoice(37);
    Y_Key.SetVoice(39);
}

void Tone_Cc::Tab_KeyPlay(int time){
    Tab_Key.VoicePlay();
    Tab_Key.RecordTime(time);
}

void Tone_Cc::Q_KeyPlay(int time){
    Q_Key.VoicePlay();
    Q_Key.RecordTime(time);
}

void Tone_Cc::W_KeyPlay(int time){
    W_Key.VoicePlay();
    W_Key.RecordTime(time);
}

void Tone_Cc::E_KeyPlay(int time){
    E_Key.VoicePlay();
    E_Key.RecordTime(time);
    qDebug()<<"Tone_Cc";
}

void Tone_Cc::R_KeyPlay(int time){
    R_Key.VoicePlay();
    R_Key.RecordTime(time);
}

void Tone_Cc::T_KeyPlay(int time){
    T_Key.VoicePlay();
    T_Key.RecordTime(time);
}

void Tone_Cc::Y_KeyPlay(int time){
    Y_Key.VoicePlay();
    Y_Key.RecordTime(time);
}

