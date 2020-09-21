QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    pianokey.cpp \
    tone.cpp \
    tone_a.cpp \
    tone_ab.cpp \
    tone_b.cpp \
    tone_bb.cpp \
    tone_c.cpp \
    tone_cb.cpp \
    tone_cc.cpp \
    tone_d.cpp \
    tone_db.cpp \
    tone_e.cpp \
    tone_eb.cpp \
    tone_f.cpp \
    tone_ff.cpp \
    tone_g.cpp \
    tone_gb.cpp

HEADERS += \
    mainwindow.h \
    pianokey.h \
    tone.h \
    tone_a.h \
    tone_ab.h \
    tone_b.h \
    tone_bb.h \
    tone_c.h \
    tone_cb.h \
    tone_cc.h \
    tone_d.h \
    tone_db.h \
    tone_e.h \
    tone_eb.h \
    tone_f.h \
    tone_ff.h \
    tone_g.h \
    tone_gb.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
