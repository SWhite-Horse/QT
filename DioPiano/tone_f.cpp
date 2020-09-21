#include "tone_f.h"

Tone_F::Tone_F()
{
    QuoteLeft_Key.SetVoice(21);
    Key1.SetVoice(23);
    Key2.SetVoice(25);
    Key3.SetVoice(26);
    Key4.SetVoice(28);
    Key5.SetVoice(30);
    Key6.SetVoice(32);

    Key7.SetVoice(57);
    Key8.SetVoice(59);
    Key9.SetVoice(61);
    Key0.SetVoice(62);
    Minus_Key.SetVoice(64);
    Equal_Key.SetVoice(66);
    Backspace_Key.SetVoice(68);

    Tab_Key.SetVoice(33);
    Q_Key.SetVoice(35);
    W_Key.SetVoice(37);
    E_Key.SetVoice(39);
    R_Key.SetVoice(40);
    T_Key.SetVoice(42);
    Y_Key.SetVoice(44);

    U_Key.SetVoice(45);
    I_Key.SetVoice(47);
    O_Key.SetVoice(49);
    P_Key.SetVoice(50);
    BracketLeft_Key.SetVoice(52);
    BracketRight_Key.SetVoice(54);
    Backslash_Key.SetVoice(56);
}

void Tone_F::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_F::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}

