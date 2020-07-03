#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //** QTableWidget 控件 **//
    ui->tableWidget->setColumnCount(3);//** 设置列数
    //** 设置内容；行数 **//
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    ui->tableWidget->setRowCount(5);

    //** 设置正文 **//
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("张益豪"));

    //** 循环输入 **//
    QStringList sexs;
    sexs<<"♂"<<"♂"<<"♀"<<"♂"<<"♂"; //** sexs 象一个数组一样
    for(int i=0;i<5;i++){
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(sexs[i]));//** 注意第三个参数的写法
    //** int 转 QString**//
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(i+19)));//** 注意第三个参数的写法

    }



}

Widget::~Widget()
{
    delete ui;
}

