#ifndef PIANOKEY_H
#define PIANOKEY_H

#include <QWidget>
#include <QSound>
#include <QDebug>
class PianoKey
{
private:
    QString KeyName;
    QSound * Vp;
public:
    PianoKey();
   // void SetKeyName(QString keyname);
    bool SetVoice(int file_num);  //** 用于琴键初始化音乐 **//
    void VoicePlay(void);  //** 音乐播放 **//
    void VoiceStop(void);  //** 音乐停止 **//
    //bool ImageShow(void);
    //void Record(void);  //** 录制音乐 **//

};

#endif // PIANOKEY_H
