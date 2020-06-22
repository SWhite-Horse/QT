#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPushButton"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    Widget(QPushButton * btn);//构造函数是可以重写的
    void CreateBtn(QPushButton * btn=nullptr,QWidget* Wi=nullptr);
    void Test();
    ~Widget();
};
#endif // WIDGET_H
