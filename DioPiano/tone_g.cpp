#include "tone_g.h"

Tone_G::Tone_G()
{
    QuoteLeft_Key.SetVoice(23);
    Key1.SetVoice(25);
    Key2.SetVoice(27);
    Key3.SetVoice(28);
    Key4.SetVoice(30);
    Key5.SetVoice(32);
    Key6.SetVoice(34);

    Key7.SetVoice(59);
    Key8.SetVoice(61);
    Key9.SetVoice(63);
    Key0.SetVoice(64);
    Minus_Key.SetVoice(66);
    Equal_Key.SetVoice(69);
    Backspace_Key.SetVoice(70);

    Tab_Key.SetVoice(35);
    Q_Key.SetVoice(37);
    W_Key.SetVoice(39);
    E_Key.SetVoice(40);
    R_Key.SetVoice(42);
    T_Key.SetVoice(44);
    Y_Key.SetVoice(46);

    U_Key.SetVoice(47);
    I_Key.SetVoice(49);
    O_Key.SetVoice(51);
    P_Key.SetVoice(52);
    BracketLeft_Key.SetVoice(54);
    BracketRight_Key.SetVoice(56);
    Backslash_Key.SetVoice(58);
}

void Tone_G::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_G::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}
