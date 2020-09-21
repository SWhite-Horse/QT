#ifndef TONE_CB_H
#define TONE_CB_H

#include "tone.h"

class Tone_Cb : public Tone
{
public:
    int Level=-1;

    Tone_Cb();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_CB_H
