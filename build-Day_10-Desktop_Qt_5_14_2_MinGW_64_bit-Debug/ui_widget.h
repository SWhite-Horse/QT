/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *widget;
    QWidget *page_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QStackedWidget *stackedWidget;
    QWidget *w1;
    QLabel *label_3;
    QWidget *page_4;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 20, 100, 111));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 194));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        scrollArea->setWidget(scrollAreaWidgetContents);
        toolBox = new QToolBox(Widget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(190, 30, 121, 121));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 121, 43));
        toolBox->addItem(page, QString::fromUtf8("Tool Box"));
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 121, 43));
        toolBox->addItem(widget, QString::fromUtf8("QQ\345\210\227\350\241\250"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        toolBox->addItem(page_2, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 180, 181, 121));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(270, 180, 131, 91));
        w1 = new QWidget();
        w1->setObjectName(QString::fromUtf8("w1"));
        label_3 = new QLabel(w1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 81, 41));
        stackedWidget->addWidget(w1);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label = new QLabel(page_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 111, 41));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 60, 111, 31));
        stackedWidget->addWidget(page_4);
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(250, 290, 80, 20));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(350, 290, 80, 20));
        dockWidget = new QDockWidget(Widget);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setGeometry(QRect(40, 360, 161, 121));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(290, 360, 72, 22));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(272, 450, 131, 31));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(233, 501, 141, 71));

        retranslateUi(Widget);

        toolBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Scroll Area", nullptr));
        pushButton_6->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Widget", "Tool Box", nullptr));
        toolBox->setItemText(toolBox->indexOf(widget), QCoreApplication::translate("Widget", "QQ\345\210\227\350\241\250", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Widget", "\351\273\221\345\220\215\345\215\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "bai\347\231\276\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "\350\260\267\346\255\214", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "zhe\350\277\231\346\230\257\347\254\254\344\272\214\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Stack,\345\217\257\344\273\245\345\210\207\346\215\242yye2", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\205\267\344\275\223y\350\246\201\351\205\215\345\220\210\346\247\275\344\275\277\347\224\250", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "shang'yi\344\270\212\344\270\200\351\241\265", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "xia'ye ", nullptr));
        lineEdit->setText(QCoreApplication::translate("Widget", "\345\215\225\350\241\214shu\350\276\223\345\205\245k\346\241\206\357\274\214\345\217\257\344\273\245\350\256\276\347\275\256\345\257\206\347\240\201\346\250\241\345\274\217", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Label \345\217\257\344\273\245\346\230\276\347\244\272\345\233\276/don\345\212\250\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
