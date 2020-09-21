#include "tone_gb.h"

Tone_Gb::Tone_Gb()
{
    QuoteLeft_Key.SetVoice(22);
    Key1.SetVoice(24);
    Key2.SetVoice(26);
    Key3.SetVoice(27);
    Key4.SetVoice(29);
    Key5.SetVoice(31);
    Key6.SetVoice(33);

    Key7.SetVoice(58);
    Key8.SetVoice(60);
    Key9.SetVoice(62);
    Key0.SetVoice(63);
    Minus_Key.SetVoice(65);
    Equal_Key.SetVoice(67);
    Backspace_Key.SetVoice(69);

    Tab_Key.SetVoice(34);
    Q_Key.SetVoice(36);
    W_Key.SetVoice(38);
    E_Key.SetVoice(39);
    R_Key.SetVoice(41);
    T_Key.SetVoice(43);
    Y_Key.SetVoice(45);

    U_Key.SetVoice(46);
    I_Key.SetVoice(48);
    O_Key.SetVoice(50);
    P_Key.SetVoice(51);
    BracketLeft_Key.SetVoice(53);
    BracketRight_Key.SetVoice(55);
    Backslash_Key.SetVoice(57);
}

void Tone_Gb::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_Gb::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}

