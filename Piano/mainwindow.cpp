#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pianokey.h"
#include "tone.h"
#include "tone_c.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tone_C c;
    c.E_KeyPlay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

