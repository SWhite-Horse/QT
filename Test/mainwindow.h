#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QTimer>
#include <QElapsedTimer>
#include <QSound>
#include <QDataStream>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool ister=0;
    int st,end;
public:

    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    QSound * s;
    QTimer *timr;
    QElapsedTimer  *tim;
    QSound * ss=new QSound(":/voice/40_.wav");
    QSound * sss=new QSound(":/voice/40.wav");
//    QMediaPlayer * ss2=new QMediaPlayer;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
