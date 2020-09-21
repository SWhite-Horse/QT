#ifndef TONE_EB_H
#define TONE_EB_H

#include "tone.h"

class Tone_Eb : public Tone
{
public:
    int Level=4;
    Tone_Eb();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_EB_H
