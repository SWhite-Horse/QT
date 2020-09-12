#ifndef TONE_H
#define TONE_H

#include <QWidget>

#include "pianokey.h"

class Tone
{
public:
    PianoKey  Q_Key,W_Key,E_Key,R_Key,T_Key,Y_Key,U_Key,
              I_Key,O_Key,P_Key,BracketLeft_Key,
              Backslash_Key,BracketRight_Key,Tab_Key,
              Key0,Key1,Key2,Key3,Key4,Key5,Key6,Key7,
              Key8,Key9,Minus_Key,Equal_Key,AsciiTilde_Key,Back_Key;
              // A_Key,S_Key,D_Key,F_Key,G_Key,H_Key,J_Key,K_Key,L_Key,
    Tone();

//    virtual void AsciiTilde_KeyPlay(int){};
//    virtual void Key1_Play(int){};
//    virtual void Key2_Play(int){};
//    virtual void Key3_Play(int){};
//    virtual void Key4_Play(int){};
//    virtual void Key5_Play(int){};
//    virtual void Key6_Play(int){};

//    virtual void Key7_Play(int){};
//    virtual void Key8_Play(int){};
//    virtual void Key9_Play(int){};
//    virtual void Key0_Play(int){};
//    virtual void Minus_KeyPlay(int){};
//    virtual void Equal_KeyPlay(int){};
//    virtual void Back_KeyPlay(int){};

    virtual void Tab_KeyPlay(int){};
    virtual void Q_KeyPlay(int){};
    virtual void W_KeyPlay(int){};
    virtual void E_KeyPlay(int){};
    virtual void R_KeyPlay(int){};
    virtual void T_KeyPlay(int){};
    virtual void Y_KeyPlay(int){};

//    virtual void U_KeyPlay(int){};
//    virtual void I_KeyPlay(int){};
//    virtual void O_KeyPlay(int){};
//    virtual void P_KeyPlay(int){};
//    virtual void BracketLeft_KeyPlay(int){};
//    virtual void BracketRight_KeyPlay(int){};
//    virtual void Backslash_KeyPlay(int){};

};

#endif // TONE_H
