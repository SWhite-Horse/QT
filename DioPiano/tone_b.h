#ifndef TONE_B_H
#define TONE_B_H

#include "tone.h"

class Tone_B : public Tone
{
public:
    Tone_B();
    int Level=-2;
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_B_H
