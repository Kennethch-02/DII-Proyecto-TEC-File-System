QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HuffTree.cpp \
    Split.cpp \
    controller_node.cpp \
    disknode.cpp \
    node.cpp \
    tecfs.cpp \
    dialog.cpp \
    server.cpp \
    thread.cpp \
    client.cpp \
    main.cpp \
    thread_read.cpp \
    thread_write.cpp

HEADERS += \
    HuffTree.h \
    Split.h \
    controller_node.h \
    dialog.h \
    disknode.h \
    node.h \
    server.h \
    thread.h \
    client.h \
    tecfs.h \
    thread_read.h \
    thread_write.h

FORMS += \
    dialog.ui\
    tecfs.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
