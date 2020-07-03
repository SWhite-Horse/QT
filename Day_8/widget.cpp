#include "widget.h"
#include "ui_widget.h"
#include "QTreeWidget"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //** treeWidget 的使用**//

    //** 注意：1、头Labels的设置，设置了几个，子层节点的每行就可输入几个数据
    //**      2、注意添加子节点的格式

    //** 设置水平的头 **//
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍：");//这是匿名对象的使用，不会可以写完整
    QTreeWidgetItem * item1 =new QTreeWidgetItem(QStringList()<<"力量");
    //** 加载顶层节点 **//
    ui->treeWidget->addTopLevelItem(item1);
    //** 加载子节点**//
    QTreeWidgetItem * H1 = new QTreeWidgetItem(QStringList()<<"张益豪"<<"释放黑炮之力");
    item1->addChild(H1);

    QTreeWidgetItem * item2 =new QTreeWidgetItem(QStringList()<<"敏捷");
    ui->treeWidget->addTopLevelItem(item2);
    QTreeWidgetItem * item3 =new QTreeWidgetItem(QStringList()<<"智慧");
    ui->treeWidget->addTopLevelItem(item3);


}

Widget::~Widget()
{
    delete ui;
}

