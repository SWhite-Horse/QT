#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "QCheckBox"
#include "QListWidget"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->rB2,&QRadioButton::clicked,[=]()mutable{
                qDebug()<<"女人啊！";
            });
    //** QCheckBox 属性最下面可设置半选，输出1 **//
    connect(ui->pig,&QCheckBox::stateChanged,[=](int state)mutable{
                qDebug()<<state;
            });

    //** 用listWidget 写诗 **//
    QListWidgetItem * item = new QListWidgetItem("这不是一首诗");
    //** 将一行诗放入ListWidget **//
    ui->listWidget->addItem(item);
    item->setTextAlignment(4);
    //** QStringList 是QT下的一个重载库，可如下使用 **//
    QStringList list;
    list<<"这不是一首诗，"<<"我不是什么诗人，"<<"啊！啊！"<<"打死了！打死了！";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

