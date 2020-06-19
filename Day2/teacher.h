#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);
//** 这里是自定义信号书写位置 **//
//** 返回值是void，只需要声明，无需实现 **//
//** 可以有参，也就是可以重载**//
signals:
    void hungry();
    void hungry(QString FoodName); //QString 字符串的重载

};

#endif // TEACHER_H
