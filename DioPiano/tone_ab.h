#ifndef TONE_AB_H
#define TONE_AB_H

#include "tone.h"

class Tone_Ab : public Tone
{
public:
    int Level=-5;
    Tone_Ab();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_AB_H
