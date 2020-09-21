#ifndef TONE_GB_H
#define TONE_GB_H

#include "tone.h"

class Tone_Gb : public Tone
{
public:
    Tone_Gb();
    int Level=8;
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_GB_H
