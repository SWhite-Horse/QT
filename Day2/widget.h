#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPushButton"
#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void ClasOver();
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher * Mk;
    Student * Scp;
};
#endif // WIDGET_H
