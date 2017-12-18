#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T10:09:08
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test-server-gui
TEMPLATE = app


SOURCES += main.cpp\
        testserver.cpp \
        mainwindow.cpp \
    testcommand.cpp

HEADERS  += mainwindow.h \
            testserver.h \
    testcommand.h

FORMS    += mainwindow.ui
