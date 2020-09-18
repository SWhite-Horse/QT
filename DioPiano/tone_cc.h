#ifndef TONE_CC_H
#define TONE_CC_H

//**********//
//**      **//
//**********//

#include <QWidget>
#include "tone.h"

class Tone_Cc : public Tone
{
public:
    int Level=1;
    Tone_Cc();

    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);

};

#endif // TONE_CC_H
