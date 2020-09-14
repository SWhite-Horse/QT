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
#include "tone.h"
#include "tone_c.h"
#include "tone_cc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool Is_tenuto_space=0;//** 用于判断空格键，改变延音
    bool Is_record=0;
public:

    //** 音调定义区 **//
    Tone *tone;
    Tone_C c;
    Tone_Cc cc;


    QFile file;


    QElapsedTimer *tim=NULL; //** 记录用的总时钟

    MainWindow(QWidget *parent = nullptr);

    //** 按键函数区 **//

    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject * obj,QEvent * event); //** 特别处理Tab和Space
   // void keyReleaseEvent(QKeyEvent *event);

    //** 音频函数区 **//

    void TenutoChange(void); //** 改变延音状态
    void Record(QString); //** 录音函数接口
    void StopRecord();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
