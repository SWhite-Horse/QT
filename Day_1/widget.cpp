#include "widget.h"
#include "QPushButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * btn =new QPushButton;
    btn->show();  //仅使用这个函数会产生弹出的按钮//

     //** 设定对象树的父亲，这里的parent就是你要放置这个按钮的地方（Widget） ** //
    btn->setParent(this);
    btn->setText("I Love You！");

    //** 按照空间大小创建窗口(有缺陷），但是同时等于上两个函数 **//
    QPushButton * btn2 =new QPushButton("Love U Too!",this);
    //** 按钮重置大小 **//
    btn->resize(200,20);

    //** 移动按钮 **//
    btn->move(50,50);
    btn2->move(50,150);

    //** 重置窗口大小 **//
    resize(600,400);
    //** 设置窗口固定大小（不可改变了） **//
    setFixedSize(600,500);

    //** 窗口标题设置 **//
    setWindowTitle("Data");

    //** connect(信号发送者，发送的信号，信号的接收者，槽（slot）（处理）),注意都是指针 **//
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
}

Widget::~Widget()
{
}

//命名规范 ： 大写的首字母
//快捷键   ： Ctrl+B 编译  Ctrl+/ 注释
//整行移动 ： Ctrl+Shift+↑
//自动对齐 ： Ctrl+I
//同名之间的 .h 和 .cpp 切换 F4
//#include <QDebug>    qDebug = cout,可以用来调试
//构造析构会按对象树执行，也就是我们不用自己去析构挂在QObject或其子类下的对象，简化了代码工作
