#include "tone_bb.h"

Tone_Bb::Tone_Bb()
{
    QuoteLeft_Key.SetVoice(13);
    Key1.SetVoice(15);
    Key2.SetVoice(17);
    Key3.SetVoice(18);
    Key4.SetVoice(20);
    Key5.SetVoice(22);
    Key6.SetVoice(24);

    Key7.SetVoice(49);
    Key8.SetVoice(51);
    Key9.SetVoice(53);
    Key0.SetVoice(54);
    Minus_Key.SetVoice(56);
    Equal_Key.SetVoice(58);
    Backspace_Key.SetVoice(60);

    Tab_Key.SetVoice(25);
    Q_Key.SetVoice(27);
    W_Key.SetVoice(29);
    E_Key.SetVoice(30);
    R_Key.SetVoice(32);
    T_Key.SetVoice(34);
    Y_Key.SetVoice(36);

    U_Key.SetVoice(37);
    I_Key.SetVoice(39);
    O_Key.SetVoice(41);
    P_Key.SetVoice(42);
    BracketLeft_Key.SetVoice(44);
    BracketRight_Key.SetVoice(46);
    Backslash_Key.SetVoice(48);
}

void Tone_Bb::Key_Play(PianoKey & Key){
    Key.VoicePlay();
};

void Tone_Bb::Key_Play(PianoKey & Key,int time=0){
    Key.VoicePlay();
    Key.RecordTime(time);
};
