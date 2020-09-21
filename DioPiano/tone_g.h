#ifndef TONE_G_H
#define TONE_G_H

#include "tone.h"

class Tone_G : public Tone
{
public:
    Tone_G();
    int Level=9;
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_G_H
