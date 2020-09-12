#include "tone_c.h"
#include <QDebug>
Tone_C::Tone_C()
{
    AsciiTilde_Key.SetVoice(16);
    Key1.SetVoice(18);
    Key2.SetVoice(20);
    Key3.SetVoice(21);
    Key4.SetVoice(23);
    Key5.SetVoice(25);
    Key6.SetVoice(27);

    Key7.SetVoice(52);
    Key8.SetVoice(54);
    Key9.SetVoice(56);
    Key0.SetVoice(57);
    Minus_Key.SetVoice(59);
    Equal_Key.SetVoice(61);
    Back_Key.SetVoice(63);

    Tab_Key.SetVoice(28);
    Q_Key.SetVoice(30);
    W_Key.SetVoice(32);
    E_Key.SetVoice(33);
    R_Key.SetVoice(35);
    T_Key.SetVoice(37);
    Y_Key.SetVoice(39);

    U_Key.SetVoice(40);
    I_Key.SetVoice(42);
    O_Key.SetVoice(44);
    P_Key.SetVoice(45);
    BracketLeft_Key.SetVoice(47);
    BracketRight_Key.SetVoice(49);
    Backslash_Key.SetVoice(51);
}


void Tone_C::Tab_KeyPlay(int time){
    Tab_Key.VoicePlay();
    Tab_Key.RecordTime(time);
}

void Tone_C::Q_KeyPlay(int time){
    Q_Key.VoicePlay();
    Q_Key.RecordTime(time);
}

void Tone_C::W_KeyPlay(int time){
    W_Key.VoicePlay();
    W_Key.RecordTime(time);
}

void Tone_C::E_KeyPlay(int time){
    E_Key.VoicePlay();
    E_Key.RecordTime(time);
     qDebug()<<"Tone_C";
}

void Tone_C::R_KeyPlay(int time){
    R_Key.VoicePlay();
    R_Key.RecordTime(time);
}

void Tone_C::T_KeyPlay(int time){
    T_Key.VoicePlay();
    T_Key.RecordTime(time);
}

void Tone_C::Y_KeyPlay(int time){
    Y_Key.VoicePlay();
    Y_Key.RecordTime(time);
}
