#include "widget.h"

#include <QApplication> //**包含一个应用程序类的头文件**//

// argc 是命令行变量的数量， argv 命令行变量的数组， 意思是 接受鼠标、键盘的命令
int main(int argc, char *argv[])
{
    //** a 是应用程序对象，在QT中，有且只有一个 ** //
    QApplication a(argc, argv);
    Widget w;
    w.show();  //**必须show 才会显示窗口**//
    return a.exec();  //** 让应用程序进入消息循环 **//
}
