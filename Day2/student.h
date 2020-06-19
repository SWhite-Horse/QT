#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
//** 槽函数可以写在public和全局 **//
//** 返回值void，需要声明，也需要实现 **//
//** 可以有参数，重载 **//
public:
    explicit Student(QObject *parent = nullptr);

    void Treat();
    void Treat(QString FoodName);
signals:

};

#endif // STUDENT_H
