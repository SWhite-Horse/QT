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
    QString filename,filename_; //** 声音文件名的初始化
    int num; //** 用于记录按键
    int BorW; //** 记录黑键还是白键
    QSound * V_short; //** 键盘声音的进入
    QSound * V_long; //** 键盘声音的进入
    int Pr_time; //** 用于记录按键时长
    int Is_tenuto=0;  //** 是否延音,只用来记录，不用来判断，判断的延音在window里定义

    QString Path;//成员属性 保存图片路径
    QPixmap pix;

public:
    //explicit PianoKey(QWidget *parent = nullptr);

    PianoKey();


    int SetVoice(int);  //** 用于琴键初始化音乐文件名 **//
    int setVoice(int);  //** 重载版本，这个函数会创建子线程 **//
    void VoicePlay(void);  //** 音乐播放 **//

    int SetImage(int);  //** 用于琴键初始化图片并加载显示 **//
    void Press_Image(void);   //** 按键按下动画 **//
    void Release_Image(void);   //** 按键按下动画 **//

    int GetTenuto(void);
    void TenutoChange(int); //** Change Is_tenuto **//

    void RecordTime(int); //** record time to make it could be replay **//
    int GetTime(void);

    int GetNum(void);
    bool GetV_S();

    QString Record(void);  //** 录制音乐 **//

    friend QTextStream& operator<<(QTextStream&,PianoKey&);
    friend QTextStream& operator>>(QTextStream&,PianoKey&);
signals:

};

#endif // PIANOKEY_H
