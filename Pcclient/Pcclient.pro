#-------------------------------------------------
#
# Project created by QtCreator 2018-03-05T00:45:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pcclient
TEMPLATE = app

QMAKE_CXXFLAGS+= -std=c++11

QMAKE_LFLAGS += -std=c++11

QMAKE_LINK += -pthread

LIBS += -L/usr/lib -levent

SOURCES += main.cpp\
        pcclient.cpp \
    udpclient.cpp \
    tcpclient.cpp \
    payloadproc.cpp \
    clientbase.cpp \
    timertaskmanager.cpp \
    packagemanager.cpp \
    threadpool.cpp

HEADERS  += pcclient.h \
    udpclient.h \
    tcpclient.h \
    payloadproc.h \
    common.h \
    crossplatform.h \
    clientbase.h \
    timertaskmanager.h \
    packagemanager.h \
    singleton.h \
    spinlock.h \
    threadpool.h \
    concurrent_queue.h

FORMS    += pcclient.ui


