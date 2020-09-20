#include "tone_cc.h"
#include <QDebug>

Tone_Cc::Tone_Cc()
{
    QuoteLeft_Key.SetVoice(17);
    Key1.SetVoice(19);
    Key2.SetVoice(21);
    Key3.SetVoice(22);
    Key4.SetVoice(24);
    Key5.SetVoice(26);
    Key6.SetVoice(28);

    Key7.SetVoice(53);
    Key8.SetVoice(55);
    Key9.SetVoice(57);
    Key0.SetVoice(58);
    Minus_Key.SetVoice(60);
    Equal_Key.SetVoice(62);
    Backspace_Key.SetVoice(64);

    Tab_Key.SetVoice(29);
    Q_Key.SetVoice(31);
    W_Key.SetVoice(33);
    E_Key.SetVoice(34);
    R_Key.SetVoice(36);
    T_Key.SetVoice(38);
    Y_Key.SetVoice(40);

    U_Key.SetVoice(41);
    I_Key.SetVoice(43);
    O_Key.SetVoice(45);
    P_Key.SetVoice(46);
    BracketLeft_Key.SetVoice(48);
    BracketRight_Key.SetVoice(50);
    Backslash_Key.SetVoice(52);
}

void Tone_Cc::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_Cc::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}

