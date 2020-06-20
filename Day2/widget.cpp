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
    //disconnect(btn,&QPushButton::clicked,this,&Widget::ClasOver);

    //** Lambda 表达式 **//
    //** 说明：①形式是[]()mutable->返回值类型{};最后再加一个()是在调用这个匿名函数
    //**      ②[]里面可以是 = & this a &a,()是参数列表，{}是函数主体（详情用法上网搜一下）
    //**      ③Lambda的存在方便了代码的书写，其一个重要应用是在connect里面作为槽函数，如下示例
    //**      ④mutable一般省略，但是当我们通过值传递进来参数，而且需要修改它时，就要加，
    //**        而且参数列表不能省略，且注意，这里修改的是值传递之后的复制品，而非参数本体
    //**      ⑤->返回值类型，只在需要的时候书写，一般和需要它返回值的参数的类型保持一致
    //**      ⑥
    [=](){
        btn->setText("下课");
    }();
    QPushButton *btn3=new QPushButton(this); //切勿忘记设置*parent
    btn3->setText("关闭");
    btn3->move(100,0);
    connect(btn3,&QPushButton::clicked,this,[=](){
        close();
        //btn->setText("上课");
    });  //且当参数三为this，四为Lambda时，this可以省略

}
void Widget::ClasOver(){

    emit Mk->hungry("屎");  //**emit 用于触发信号
};

Widget::~Widget()
{
    delete ui;
}

