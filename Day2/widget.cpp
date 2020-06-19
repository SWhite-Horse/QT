#include "widget.h"
#include "ui_widget.h"


//** 需求 ：下课老师说饿了，学生响应，请吃饭
//** 类：Teacher，Student
//类的创建

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建老师和学生的对象
    Mk=new Teacher(this);
    Scp=new Student(this);

    //** 在有重载之后，就需要写一个函数指针指向这些函数，用来传递进connect函数（就像句柄） **//
    //** 注意函数指针的写法，①void;②作用域，如Teacher：： ;③后面的参数，无参就为 () ;
    void(Teacher:: * TeacherSingal)(QString) = &Teacher::hungry;
    void(Student:: * StudentSlot)(QString) = &Student::Treat;

    void(Teacher:: * TeacherSingalV)() = &Teacher::hungry;
    void(Student:: * StudentSlotV)() = &Student::Treat;

    connect(Mk,TeacherSingal,Scp,StudentSlot);
    connect(Mk,TeacherSingalV,Scp,StudentSlotV);
    ClasOver();//**必须先连接，这个函数用于触发信号

    QPushButton * btn=new QPushButton("ClassOver",this);
    this->resize(600,400);

    //** 信号连结槽,（此时已经被下面断开了） **//
    connect(btn,&QPushButton::clicked,this,&Widget::ClasOver);

    //** 信号连接信号,后者连结的信号也会同时被触发，意思是上面的那种形式就不必要了，**//
    //** 无需再定义一个ClassOver去触发信号 **//
    connect(btn,&QPushButton::clicked,Mk,TeacherSingalV);

    //** 断开信号 **//
    disconnect(btn,&QPushButton::clicked,this,&Widget::ClasOver);
    
    //** 同一个信号和槽的参数的类型必须一一对应，但信号的参数个数可以多于槽的参数个数，信号和槽都可以多对多 **//
}
void Widget::ClasOver(){

    emit Mk->hungry("屎");  //**emit 用于触发信号
};

Widget::~Widget()
{
    delete ui;
}

