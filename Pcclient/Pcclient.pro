#-------------------------------------------------
#
# Project created by QtCreator 2018-03-05T00:45:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pcclient
TEMPLATE = app


SOURCES += main.cpp\
        pcclient.cpp \
    udpclient.cpp \
    tcpclient.cpp \
    payloadproc.cpp \
    clientbase.cpp \
    timertaskmanager.cpp

HEADERS  += pcclient.h \
    udpclient.h \
    tcpclient.h \
    payloadproc.h \
    common.h \
    crossplatform.h \
    clientbase.h \
    timertaskmanager.h

FORMS    += pcclient.ui

QMAKE_CXXFLAGS += -std=c++14

QMAKE_LINK += -pthread

LIBS += -L/usr/lib -levent
