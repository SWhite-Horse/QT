#include "tone_cb.h"

Tone_Cb::Tone_Cb()
{
    QuoteLeft_Key.SetVoice(15);
    Key1.SetVoice(17);
    Key2.SetVoice(19);
    Key3.SetVoice(20);
    Key4.SetVoice(22);
    Key5.SetVoice(24);
    Key6.SetVoice(26);

    Key7.SetVoice(51);
    Key8.SetVoice(53);
    Key9.SetVoice(55);
    Key0.SetVoice(56);
    Minus_Key.SetVoice(58);
    Equal_Key.SetVoice(60);
    Backspace_Key.SetVoice(62);

    Tab_Key.SetVoice(27);
    Q_Key.SetVoice(29);
    W_Key.SetVoice(31);
    E_Key.SetVoice(32);
    R_Key.SetVoice(34);
    T_Key.SetVoice(36);
    Y_Key.SetVoice(38);

    U_Key.SetVoice(39);
    I_Key.SetVoice(41);
    O_Key.SetVoice(43);
    P_Key.SetVoice(44);
    BracketLeft_Key.SetVoice(46);
    BracketRight_Key.SetVoice(48);
    Backslash_Key.SetVoice(50);
}

void Tone_Cb::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};

void Tone_Cb::Key_Play(PianoKey & Key,int time=0){
    Key.VoicePlay();
    Key.RecordTime(time);
};
