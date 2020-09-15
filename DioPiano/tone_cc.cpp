#include "tone_cc.h"
#include <QDebug>

Tone_Cc::Tone_Cc()
{
    Tab_Key.SetVoice(29);
    Q_Key.SetVoice(31);
    W_Key.SetVoice(33);
    E_Key.SetVoice(34);
    R_Key.SetVoice(36);
    T_Key.SetVoice(38);
    Y_Key.SetVoice(40);
}

void Tone_Cc::Key_Play(PianoKey& Key,int time){
    Key.VoicePlay();
    Key.RecordTime(time);
}

