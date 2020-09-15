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
    Backspace_Key.SetVoice(63);

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

void Tone_C::Key_Play(PianoKey & Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
};

//void Tone_C::AsciiTilde_KeyPlay(int time){
//    AsciiTilde_Key.VoicePlay();
//    AsciiTilde_Key.RecordTime(time);
//};


