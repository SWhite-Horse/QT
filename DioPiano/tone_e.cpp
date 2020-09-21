#include "tone_e.h"

Tone_E::Tone_E()
{

    QuoteLeft_Key.SetVoice(20);
    Key1.SetVoice(22);
    Key2.SetVoice(24);
    Key3.SetVoice(25);
    Key4.SetVoice(27);
    Key5.SetVoice(29);
    Key6.SetVoice(31);

    Key7.SetVoice(56);
    Key8.SetVoice(58);
    Key9.SetVoice(60);
    Key0.SetVoice(61);
    Minus_Key.SetVoice(63);
    Equal_Key.SetVoice(65);
    Backspace_Key.SetVoice(67);

    Tab_Key.SetVoice(32);
    Q_Key.SetVoice(34);
    W_Key.SetVoice(36);
    E_Key.SetVoice(37);
    R_Key.SetVoice(39);
    T_Key.SetVoice(41);
    Y_Key.SetVoice(43);

    U_Key.SetVoice(44);
    I_Key.SetVoice(46);
    O_Key.SetVoice(48);
    P_Key.SetVoice(49);
    BracketLeft_Key.SetVoice(51);
    BracketRight_Key.SetVoice(53);
    Backslash_Key.SetVoice(55);
}

void Tone_E::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};


void Tone_E::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}
