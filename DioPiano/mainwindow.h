#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
#include <QEvent>
#include <QDebug>
#include <pianokey.h>
#include <QElapsedTimer>
#include <QDataStream>
#include <QFile>
#include <QKeyEvent>
#include "tone_ab.h"
#include "tone_a.h"
#include "tone_bb.h"
#include "tone_b.h"
#include "tone_cb.h"
#include "tone_c.h"
#include "tone_cc.h"
#include "tone_db.h"
#include "tone_d.h"
#include "tone_e.h"
#include "tone_eb.h"
#include "tone_f.h"
#include "tone_ff.h"
#include "tone_gb.h"
#include "tone_g.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool Is_tenuto_space=0;//** 用于判断空格键，改变延音
    bool Is_record=0;
public:

    MainWindow(QWidget *parent = nullptr);

    //** 音调定义区 **//
    Tone *tone;

    Tone_Ab ab;
    Tone_A a;
    Tone_Bb bb;
    Tone_B b;
    Tone_Cb cb;
    Tone_C c;
    Tone_Cc cc;
    Tone_Db db;
    Tone_D d;
    Tone_Eb eb;
    Tone_E e;
    Tone_F f;
    Tone_Ff ff;
    Tone_G g;
    Tone_Gb gb;

    QFile file;
    QPixmap pix1,pix2,pix3,pix4;
    QElapsedTimer *tim=NULL; //** 记录用的总时钟

    //** 按键定义区 **//
    PianoKey TKey[88];

    //** 按键函数区 **//

    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject * obj,QEvent * event); //** 特别处理Tab和Space
    void keyReleaseEvent(QKeyEvent *event);

    //** 音频函数区 **//

    void TenutoChange(void); //** 改变延音状态
    void Record(QString); //** 录音函数接口
    void Replay(QString);
    void StopRecord();

    //** 图像处理区 **//

    //重写paintEvent事件 铺设背景
    void paintEvent(QPaintEvent *);
    void Drawmap(int);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
