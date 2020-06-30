#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenuBar"
#include "QToolBar"
#include "QPushButton"
#include "QStatusBar"
#include "QLabel"
#include "QDockWidget"
#include "QTextEdit"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600,500);
    setWindowTitle("Try");//** 设置标题

    //** 菜单栏创建,最多只有一个 **//
    QMenuBar * bar=menuBar(); //** menubar已经被创建在对象树下，所以可以不人为加在对象树下
    setMenuBar(bar);
    //** 创建菜单 **//
    QMenu * fileMenu = bar->addMenu("文件");  //返回值是一个QMenu * 地址
    QMenu * editMenu = bar->addMenu("编辑");
    //** 创建菜单项 **//
    QAction * NewAction = fileMenu->addAction("新建");    // 菜单的选项,返回一个指针，可以被利用，如下文中的工具栏
    fileMenu->addSeparator();
    QAction * OpenAction = fileMenu->addAction("打开");
    //** 添加分隔线 **//
    fileMenu->addSeparator();


    //** 工具栏，可以有多个 **//
    QToolBar * toolBar = new QToolBar(this);
    //** 将工具栏加在窗口中，若不使用，则是一个可以移动的，单独的栏 **//
    addToolBar(Qt::LeftToolBarArea,toolBar); //** 第一个参数是方位，只有一个参数时，默认在顶部
    //** 后期设置只允许左右停靠 **//
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::TopToolBarArea);
    //** 后期设置不允许浮动 **//
    toolBar->setFloatable(0);
    //** 后期设置不允许移动 **//
    //toolBar->setMovable(0);
    //** 工具栏添加选项 **//
    toolBar->addAction(NewAction);//** 这里其实是和上文中的菜单栏共用了一个“新建”
    toolBar->addAction(OpenAction);
    //** 工具栏添加控件 **//
    QPushButton * btn=new QPushButton("aa",this);
    toolBar->addWidget(btn); //** 因为QPushButton的父类是QWidget


    //** 状态栏，只能有一个 **//
    QStatusBar * stBar = statusBar();//** 同样不用加入对象树
    setStatusBar(stBar);
    //** 添加标签 **//
    QLabel * label1= new QLabel("提示信息",this);//** 使用的方法和Button基本一致
    stBar->addWidget(label1);

    QLabel * label2= new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2,0);
    //** 设置中心部件,只有一个 **//
    QTextEdit * edit = new QTextEdit(this);//** 相当于一个文本框
    setCentralWidget(edit);//** 参数可以是其它的控件
    //** 铆接部件（浮动窗口），可有多个 **//
    QDockWidget * dock=new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);

}

MainWindow::~MainWindow()
{
    delete ui;
}

