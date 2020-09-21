#ifndef TONE_FF_H
#define TONE_FF_H

#include "tone.h"

class Tone_Ff : public Tone
{
public:
    int Level=7;
    Tone_Ff();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_FF_H
