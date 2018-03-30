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

DEFINES += QT_NO_FOREACH

LIBS += -L/usr/lib -levent

SOURCES += main.cpp\
        pcclient.cpp \
    Client/clientbase.cpp \
    Client/tcpclient.cpp \
    Client/udpclient.cpp \
    Common/common.cpp \
    Common/threadpool.cpp \
    Common/timer.cpp \
    Common/timertaskmanager.cpp \
    KCP/connection.cpp \
    KCP/connectionmanager.cpp \
    KCP/connnectioncontainer.cpp \
    KCP/kcptype.cpp \
    Stream/streambase.cpp \
    Stream/streamflatbuf.cpp \
    Stream/streamhex.cpp \
    Stream/streamprotobuf.cpp \
    KCP/ThirdParty/ikcp.c \
    pkghandler.cpp \
    statics.cpp

HEADERS  += pcclient.h \
    Client/clientbase.h \
    Client/tcpclient.h \
    Client/udpclient.h \
    Common/common.h \
    Common/concurrent_priority_queue.h \
    Common/concurrent_queue.h \
    Common/concurrent_unordered_map.h \
    Common/crossplatform.h \
    Common/singleton.h \
    Common/spinlock.h \
    Common/threadpool.h \
    Common/timer.h \
    Common/timertaskmanager.h \
    KCP/ThirdParty/ikcp.h \
    KCP/connection.h \
    KCP/connectionmanager.h \
    KCP/connnectioncontainer.h \
    KCP/kcptype.h \
    Stream/streambase.h \
    Stream/streamflatbuf.h \
    Stream/streamhex.h \
    Stream/streamprotobuf.h \
    Common/memorypool.h \
    pkghandler.h \
    statics.h

FORMS    += pcclient.ui


