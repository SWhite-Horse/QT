#include "widget.h"
#include "QPushButton"

Widget::Widget(QWidget *parent):QWidget(parent){

};
void Widget::CreateBtn(QPushButton * btn,QWidget* Wi){
    btn = new QPushButton("Open the door",this);
    resize(600,400);
    btn->move(250,155);
    connect(btn,&QPushButton::clicked,[=](){
        btn->setText("Close!");
        //Wi->show();
    });
};
void Widget::Openthedoor(QWidget* Wi){
    Wi->show();
};
Widget::~Widget()
{
}

