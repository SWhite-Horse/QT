#include "tone_eb.h"

Tone_Eb::Tone_Eb()
{
    QuoteLeft_Key.SetVoice(19);
    Key1.SetVoice(21);
    Key2.SetVoice(23);
    Key3.SetVoice(25);
    Key4.SetVoice(26);
    Key5.SetVoice(28);
    Key6.SetVoice(31);

    Key7.SetVoice(55);
    Key8.SetVoice(57);
    Key9.SetVoice(59);
    Key0.SetVoice(60);
    Minus_Key.SetVoice(62);
    Equal_Key.SetVoice(64);
    Backspace_Key.SetVoice(66);

    Tab_Key.SetVoice(32);
    Q_Key.SetVoice(34);
    W_Key.SetVoice(36);
    E_Key.SetVoice(37);
    R_Key.SetVoice(38);
    T_Key.SetVoice(40);
    Y_Key.SetVoice(42);

    U_Key.SetVoice(43);
    I_Key.SetVoice(45);
    O_Key.SetVoice(47);
    P_Key.SetVoice(48);
    BracketLeft_Key.SetVoice(50);
    BracketRight_Key.SetVoice(52);
    Backslash_Key.SetVoice(54);
}

void Tone_Eb::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_Eb::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}

