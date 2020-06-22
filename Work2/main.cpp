#include "widget.h"
#include "QPushButton"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget W1,W2;
    QPushButton *btn=nullptr;
    Widget W3(btn);
    Widget * W=&W3;
    QPushButton * btn2=nullptr;
    W1.CreateBtn(btn2,W);
    W1.show();
    return a.exec();
}
