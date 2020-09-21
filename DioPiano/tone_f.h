#ifndef TONE_F_H
#define TONE_F_H

#include "tone.h"

class Tone_F : public Tone
{
public:
    int Level=6;
    Tone_F();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_F_H
