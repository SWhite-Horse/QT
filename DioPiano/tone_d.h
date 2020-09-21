#ifndef TONE_D_H
#define TONE_D_H

#include "tone.h"

class Tone_D : public Tone
{
public:
    int Level=3;
    Tone_D();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_D_H
