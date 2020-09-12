#ifndef PIANOKEY_H
#define PIANOKEY_H

#include <QPushButton>
#include <QSound>
#include <QTimer>
#include <QTextStream>

class PianoKey : public QPushButton
{
    Q_OBJECT   
private:
    QString filename,filename_,num; //** 声音文件名的初始化 **//
    //int Key_num; //** 用于记录按键 **//
    QSound * V_short; //** 键盘声音的进入 **//
    QSound * V_long; //** 键盘声音的进入 **//
    int Pr_time; //** 用于记录按键时长 **//
    bool Is_tenuto=0;  //** 是否延音,只用来记录，不用来判断，判断的延音在window里定义 **//
    bool Is_LongPress=0; //** 单击or长按，同上 **//

public:
    //explicit PianoKey(QWidget *parent = nullptr);


    PianoKey();

    int SetVoice(int file_num);  //** 用于琴键初始化音乐 **//
//    QTimer *timer=NULL;  //** 失败的延音做法
//    bool GetPressmode(void);
//    void PressmodeChange(void); //** Change Is_LongPress **//
    bool GetTenuto(void);
    void TenutoChange(bool); //** Change Is_tenuto **//

    void RecordTime(int st); //** record time to make it could be replay **//
    //void SetKeyName(QString keyname);

    void VoicePlay(void);  //** 音乐播放 **//
//    void VoiceStop(int ms=0);  //** 音乐停止 **//
    //bool ImageShow(void);
    QString Record(void);  //** 录制音乐 **//
    friend QTextStream& operator<<(QTextStream&,PianoKey&);
signals:

};

#endif // PIANOKEY_H
