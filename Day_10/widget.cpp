#include "widget.h"
#include "ui_widget.h"
#include "QMovie"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //** 栈控件使用(换页) **//
    ui->stackedWidget->setCurrentIndex(0);//** 设置初始页
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //** comboBox 下拉框 **//
    ui->comboBox->addItem("老黄");
    ui->comboBox->addItem("樊书记");
    ui->comboBox->addItem("敞口子");

    //** 利用Label显示动图 **//
//    QMovie * movie=new QMovie(":/资源文件名");
//    ui->label->setMovie(movie);
//    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

