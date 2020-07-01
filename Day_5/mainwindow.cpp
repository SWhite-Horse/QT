#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QAction"
#include "QDialog"
#include "QMessageBox"
#include "QColorDialog"
#include <QFileDialog>
#include "QFontDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600,400);
    //** 添加信号和槽 **//
    connect(ui->actionNew,&QAction::triggered,[=](){
        //** 对话框分为：模态对话框（同时可以对其它窗口操作）；非模态对话框（不可以对其它窗口操作） **//
//        QDialog dig(this);//** 对话框初始化
//        dig.resize(200,100);
//        dig.exec();//** 弹出,弹出之后会阻塞，因为他是模态对话框

//        QDialog * dlg = new QDialog(this);//** 非模态对话框用show函数，不过要创建在堆上
//        dlg->resize(200,100);
//        dlg->show();
//        dlg->setAttribute(Qt::WA_DeleteOnClose);//** 当关闭对话框时，删除（析构），而不是在对象树中析构，以防内存泄漏
        //** QMessageBox 类中包含的是一些系统提供的对话框，总体上是消息类对话框 **//
        //QMessageBox::critical(this,"Waring","打开失败");//** 由于是静态函数，可以直接类名+函数调用
                                                       //** 不同的函数图标不同，参数可更改
        //** 参数四： 按钮的显示；参数五：与Enter键相关联的按钮 **//
        //** 返回值是选择的按钮，也就是QMessageBox::Save|QMessageBox::Cancel，可以用来判断等操作 **//
        QMessageBox::question(this,"Q","Do you want to Save?",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
    });

    //** 对话框不止MessageBox，还有其他的标准对话框：**//

    //** 颜色对话框(选择颜色） **//
    connect(ui->actionColor,&QAction::triggered,[=](){
        QColorDialog::getColor(QColor(255,0,0));//** 会打开一个色板，参数是预设的颜色，返回值是QColor类的 颜色的信息，有三个参数，对应rgb,一个颜色
    });

    //** 文件对话框
    connect(ui->actionOpen,&QAction::triggered,[=](){
        //** 参数说明，参数3：打开路径；参数4：过滤文件类型 **//
        QFileDialog::getOpenFileName(this,"Open the door","C:/Users/SQ/Desktop/Word","*.txt");
        //** 返回值是文件路径 **//
    });

    //** 字体对话框（选择字体） **//
    connect(ui->actionFont,&QAction::triggered,[=](){
        bool ok;
        //** 第二个参数是预设值，注意类型，其它参数查；返回值是是一个font类的结构 **//
        //** 结构成员可以看（鼠标放置QFont上） **//
        QFontDialog::getFont(&ok,QFont("黑体",36));
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

