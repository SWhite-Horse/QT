#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIcon"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionNew->setIcon(QIcon("D:/LDownload/ss.png"));

    //** 使用Qt添加资源 **//
    //** ":+前缀名+文件名" **//
    ui->actionNew->setIcon(QIcon("D:/QT Works/Day_4/ss.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

