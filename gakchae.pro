#-------------------------------------------------
#
# Project created by QtCreator 2015-11-20T22:16:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gakchae
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    tile.cpp \
    map.cpp \
    menustrip.cpp \
    npcdialog.cpp

HEADERS  += mainwindow.h \
    tile.h \
    character.h \
    map.h \
    mapdata.h \
    menustrip.h \
    npcdialog.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
