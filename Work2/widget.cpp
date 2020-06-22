#include "widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}
Widget::Widget(QPushButton * btn){
    btn=new QPushButton("Tsdqd",this);
};
void Widget::CreateBtn(QPushButton * btn,QWidget* Wi){
    btn = new QPushButton("Open the door",this);
    resize(600,400);
    btn->move(250,155);
    connect(btn,&QPushButton::clicked,[=](){
        btn->setText("Close!");
        Wi->resize(200,100);
        Wi->show();
        connect(btn,&QPushButton::clicked,Wi,&Widget::close);
    });
    QPushButton *btn2 =new QPushButton("Test",this);
    connect(btn2,&QPushButton::clicked,this,&Widget::Test); //不能后面的参数多于前者
};
void Widget::Test(){
    qDebug()<<"Test";
}
Widget::~Widget()
{
}

