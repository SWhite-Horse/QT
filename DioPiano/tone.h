#ifndef TONE_H
#define TONE_H

#include <QWidget>

#include "pianokey.h"

class Tone
{
public:
    int Level=0; //** 用于改变音调
    PianoKey  Q_Key,W_Key,E_Key,R_Key,T_Key,Y_Key,U_Key,
              I_Key,O_Key,P_Key,BracketLeft_Key,
              Backslash_Key,BracketRight_Key,Tab_Key,
              Key0,Key1,Key2,Key3,Key4,Key5,Key6,Key7,
              Key8,Key9,Minus_Key,Equal_Key,QuoteLeft_Key,Backspace_Key;
              // A_Key,S_Key,D_Key,F_Key,G_Key,H_Key,J_Key,K_Key,L_Key,
    Tone();

    virtual void Key_Play(PianoKey &,int){};
    virtual void Key_Play(PianoKey &){};
};

#endif // TONE_H
