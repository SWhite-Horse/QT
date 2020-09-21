#ifndef TONE_DB_H
#define TONE_DB_H

//************************************************************//
//************************* 降D调  ****************************//
//************************************************************//

#include "tone.h"

class Tone_Db : public Tone
{
public:
    int Level=2;
    Tone_Db();
    void Key_Play(PianoKey &,int);
    void Key_Play(PianoKey &);

};

#endif // TONE_DB_H
