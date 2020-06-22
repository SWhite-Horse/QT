#include "widget.h"

#include "QPushButton"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget W1,W2;
    QPushButton * btn2=nullptr;
    W1.Openthedoor(btn2);
    W1.show();
    return a.exec();
}
