#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::Treat(){
    qDebug()<<"老师请客吃饭！"; //注意会自带换行
};
void Student::Treat(QString FN){
    //**  将QString转为 char* (也就是不带引号，string会自动带引号），
    //**  qDebug()<<"老师y要吃！"<<FN.toUtf8().data();
    qDebug()<<"老师y要吃！"<<FN; //注意会自带换行
};
