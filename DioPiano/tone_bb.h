#ifndef TONE_BB_H
#define TONE_BB_H

#include "tone.h"

class Tone_Bb : public Tone
{
public:
    int Level=-3;
    Tone_Bb();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_BB_H
