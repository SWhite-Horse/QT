/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionquit;
    QAction *actionstart;
    QAction *actionstop;
    QAction *actionplay;
    QAction *actionfresh;
    QAction *actionbug;
    QWidget *centralwidget;
    QListWidget *Help;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionquit = new QAction(MainWindow);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        actionstart = new QAction(MainWindow);
        actionstart->setObjectName(QString::fromUtf8("actionstart"));
        actionstop = new QAction(MainWindow);
        actionstop->setObjectName(QString::fromUtf8("actionstop"));
        actionplay = new QAction(MainWindow);
        actionplay->setObjectName(QString::fromUtf8("actionplay"));
        actionfresh = new QAction(MainWindow);
        actionfresh->setObjectName(QString::fromUtf8("actionfresh"));
        actionbug = new QAction(MainWindow);
        actionbug->setObjectName(QString::fromUtf8("actionbug"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setFocusPolicy(Qt::StrongFocus);
        Help = new QListWidget(centralwidget);
        Help->setObjectName(QString::fromUtf8("Help"));
        Help->setGeometry(QRect(240, 220, 734, 291));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actionquit);
        menu_2->addSeparator();
        menu_2->addAction(actionstart);
        menu_2->addAction(actionstop);
        menu_2->addAction(actionplay);
        menu_3->addSeparator();
        menu_3->addAction(actionfresh);
        menu_3->addAction(actionbug);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionquit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionstart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        actionstop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        actionplay->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        actionfresh->setText(QCoreApplication::translate("MainWindow", "\346\225\231\347\250\213", nullptr));
        actionbug->setText(QCoreApplication::translate("MainWindow", "\346\212\245\351\224\231", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\275\225\345\210\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
