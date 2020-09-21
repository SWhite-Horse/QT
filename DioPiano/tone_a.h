#ifndef TONE_A_H
#define TONE_A_H

#include "tone.h"

class Tone_A : public Tone
{
public:
    int Level=-4;
    Tone_A();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_A_H
