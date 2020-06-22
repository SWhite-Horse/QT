#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPushButton"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void CreateBtn(QPushButton * btn=nullptr,QWidget* Wi=nullptr);
    void Openthedoor(QWidget* Wi);
    ~Widget();
};
#endif // WIDGET_H
