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
//    void AsciiTilde_KeyPlay(int);
//    void Key1_Play(int);
//    void Key2_Play(int);
//    void Key3_Play(int);
//    void Key4_Play(int);
//    void Key5_Play(int);
//    void Key6_Play(int);

//    void Key7_Play(int);
//    void Key8_Play(int);
//    void Key9_Play(int);
//    void Key0_Play(int);
//    void Minus_KeyPlay(int);
//    void Equal_KeyPlay(int);
//    void Back_KeyPlay(int);

    void Tab_KeyPlay(int);
    void Q_KeyPlay(int);
    void W_KeyPlay(int);
    void E_KeyPlay(int);
    void R_KeyPlay(int);
    void T_KeyPlay(int);
    void Y_KeyPlay(int);

//    void U_KeyPlay(int);
//    void I_KeyPlay(int);
//    void O_KeyPlay(int);
//    void P_KeyPlay(int);
//    void BracketLeft_KeyPlay(int);
//    void BracketRight_KeyPlay(int);
//    void Backslash_KeyPlay(int);
//    void E_KeyStop(int ms=0);
//    void Q_KeyStop(int ms=0);
};

#endif // TONE_C_H
