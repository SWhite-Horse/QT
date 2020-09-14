#include "tone_cc.h"
#include <QDebug>

Tone_Cc::Tone_Cc()
{
    Tab_Key.SetVoice(29);
    Q_Key.SetVoice(31);
    W_Key.SetVoice(33);
    E_Key.SetVoice(34);
    R_Key.SetVoice(36);
    T_Key.SetVoice(38);
    Y_Key.SetVoice(40);
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

