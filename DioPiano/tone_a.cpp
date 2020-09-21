#include "tone_a.h"

Tone_A::Tone_A()
{
    QuoteLeft_Key.SetVoice(12);
    Key1.SetVoice(14);
    Key2.SetVoice(16);
    Key3.SetVoice(17);
    Key4.SetVoice(19);
    Key5.SetVoice(21);
    Key6.SetVoice(23);

    Key7.SetVoice(48);
    Key8.SetVoice(50);
    Key9.SetVoice(52);
    Key0.SetVoice(53);
    Minus_Key.SetVoice(55);
    Equal_Key.SetVoice(57);
    Backspace_Key.SetVoice(59);

    Tab_Key.SetVoice(24);
    Q_Key.SetVoice(26);
    W_Key.SetVoice(28);
    E_Key.SetVoice(29);
    R_Key.SetVoice(31);
    T_Key.SetVoice(33);
    Y_Key.SetVoice(35);

    U_Key.SetVoice(36);
    I_Key.SetVoice(38);
    O_Key.SetVoice(40);
    P_Key.SetVoice(41);
    BracketLeft_Key.SetVoice(43);
    BracketRight_Key.SetVoice(45);
    Backslash_Key.SetVoice(47);
}

void Tone_A::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};

void Tone_A::Key_Play(PianoKey & Key,int time=0){
    Key.VoicePlay();
    Key.RecordTime(time);
};

