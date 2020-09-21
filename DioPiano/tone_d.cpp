#include "tone_d.h"

Tone_D::Tone_D()
{
    QuoteLeft_Key.SetVoice(18);
    Key1.SetVoice(20);
    Key2.SetVoice(22);
    Key3.SetVoice(23);
    Key4.SetVoice(25);
    Key5.SetVoice(27);
    Key6.SetVoice(29);

    Key7.SetVoice(54);
    Key8.SetVoice(56);
    Key9.SetVoice(58);
    Key0.SetVoice(59);
    Minus_Key.SetVoice(61);
    Equal_Key.SetVoice(63);
    Backspace_Key.SetVoice(65);

    Tab_Key.SetVoice(30);
    Q_Key.SetVoice(32);
    W_Key.SetVoice(34);
    E_Key.SetVoice(35);
    R_Key.SetVoice(37);
    T_Key.SetVoice(39);
    Y_Key.SetVoice(41);

    U_Key.SetVoice(42);
    I_Key.SetVoice(44);
    O_Key.SetVoice(46);
    P_Key.SetVoice(47);
    BracketLeft_Key.SetVoice(49);
    BracketRight_Key.SetVoice(51);
    Backslash_Key.SetVoice(53);
}

void Tone_D::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_D::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}

