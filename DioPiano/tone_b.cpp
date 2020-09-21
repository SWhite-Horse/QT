#include "tone_b.h"

Tone_B::Tone_B()
{
    QuoteLeft_Key.SetVoice(14);
    Key1.SetVoice(16);
    Key2.SetVoice(18);
    Key3.SetVoice(19);
    Key4.SetVoice(21);
    Key5.SetVoice(23);
    Key6.SetVoice(25);

    Key7.SetVoice(50);
    Key8.SetVoice(52);
    Key9.SetVoice(54);
    Key0.SetVoice(55);
    Minus_Key.SetVoice(57);
    Equal_Key.SetVoice(59);
    Backspace_Key.SetVoice(61);

    Tab_Key.SetVoice(26);
    Q_Key.SetVoice(28);
    W_Key.SetVoice(30);
    E_Key.SetVoice(31);
    R_Key.SetVoice(33);
    T_Key.SetVoice(35);
    Y_Key.SetVoice(37);

    U_Key.SetVoice(38);
    I_Key.SetVoice(40);
    O_Key.SetVoice(42);
    P_Key.SetVoice(43);
    BracketLeft_Key.SetVoice(45);
    BracketRight_Key.SetVoice(47);
    Backslash_Key.SetVoice(49);
}

void Tone_B::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};

void Tone_B::Key_Play(PianoKey & Key,int time=0){
    Key.VoicePlay();
    Key.RecordTime(time);
};
