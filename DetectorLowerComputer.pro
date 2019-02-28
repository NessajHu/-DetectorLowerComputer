#-------------------------------------------------
#
# Project created by QtCreator 2019-02-27T16:12:35
#
#-------------------------------------------------

QT       += core gui network svg printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
CONFIG += qwt
CONFIG += debug_and_release
unix {
    INCLUDEPATH += /usr/local
    LIBS += -L"usr/local/Qwt/lib" -lqwt
} else {
    CONFIG(debug, debug|release){
        LIBS += -lqwtd
    }else{
        LIBS += -lqwt
    }
    INCLUDEPATH += D:\Qt5.10.0\5.10.0\mingw53_32\include\Qwt\
}

TARGET = DetectorLowerComputer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS QT_DLL QWT_LL

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    main.cpp \
    mainwindow.cpp \
    datadisplay.cpp \
    datahandle.cpp \
    datawave.cpp \
    statusanalysis.cpp \
    systemoption.cpp \
    tcpserver.cpp \
    keyboard.cpp \
    lineedit.cpp

HEADERS += \
    mainwindow.h \
    datadisplay.h \
    datahandle.h \
    datawave.h \
    statusanalysis.h \
    systemoption.h \
    tcpserver.h \
    keyboard.h \
    lineedit.h
