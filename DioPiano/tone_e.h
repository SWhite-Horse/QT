#ifndef TONE_E_H
#define TONE_E_H

#include "tone.h"


class Tone_E : public Tone
{
public:
    int Level=5;
    Tone_E();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_E_H
