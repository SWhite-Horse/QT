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
    Tone_Cc();

    void Tab_KeyPlay(int);
    void Q_KeyPlay(int);
    void W_KeyPlay(int);
    void E_KeyPlay(int);
    void R_KeyPlay(int);
    void T_KeyPlay(int);
    void Y_KeyPlay(int);
};

#endif // TONE_CC_H
