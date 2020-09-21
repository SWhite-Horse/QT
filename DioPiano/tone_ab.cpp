#include "tone_ab.h"

Tone_Ab::Tone_Ab()
{
    QuoteLeft_Key.SetVoice(11);
    Key1.SetVoice(13);
    Key2.SetVoice(15);
    Key3.SetVoice(16);
    Key4.SetVoice(18);
    Key5.SetVoice(20);
    Key6.SetVoice(22);

    Key7.SetVoice(47);
    Key8.SetVoice(49);
    Key9.SetVoice(51);
    Key0.SetVoice(52);
    Minus_Key.SetVoice(54);
    Equal_Key.SetVoice(56);
    Backspace_Key.SetVoice(58);

    Tab_Key.SetVoice(23);
    Q_Key.SetVoice(25);
    W_Key.SetVoice(27);
    E_Key.SetVoice(28);
    R_Key.SetVoice(30);
    T_Key.SetVoice(32);
    Y_Key.SetVoice(34);

    U_Key.SetVoice(35);
    I_Key.SetVoice(37);
    O_Key.SetVoice(39);
    P_Key.SetVoice(40);
    BracketLeft_Key.SetVoice(42);
    BracketRight_Key.SetVoice(44);
    Backslash_Key.SetVoice(46);
}

void Tone_Ab::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};

void Tone_Ab::Key_Play(PianoKey & Key,int time=0){
    Key.VoicePlay();
    Key.RecordTime(time);
};

