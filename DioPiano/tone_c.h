#ifndef TONE_C_H
#define TONE_C_H

//************************************************************//
//************************* C大调  ****************************//
//************************************************************//

#include <QWidget>
#include "tone.h"

class Tone_C : public Tone
{
public:
    int Level=0;

    Tone_C();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);
};

#endif // TONE_C_H
