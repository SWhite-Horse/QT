#ifndef TONE_H
#define TONE_H

#include <QWidget>
#include "pianokey.h"

class Tone
{

public:
    PianoKey * E_Key;
    Tone();
    void E_KeyPlay(void);
};

#endif // TONE_H
