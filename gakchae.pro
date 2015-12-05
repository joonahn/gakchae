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
    npcdialog.cpp \
    bar.cpp \
    building.cpp \
    building2.cpp \
    building2floor.cpp \
    bullet.cpp \
    color_bar.cpp \
    ending.cpp \
    game.cpp \
    gameinfo.cpp \
    gameover1.cpp \
    gameover2.cpp \
    gray_bar.cpp \
    health.cpp \
    light.cpp \
    mini_image.cpp \
    money.cpp \
    nomal_bd.cpp \
    special_bd.cpp \
    summoner.cpp \
    taxi.cpp \
    taxi_distance.cpp

HEADERS  += mainwindow.h \
    tile.h \
    character.h \
    map.h \
    mapdata.h \
    menustrip.h \
    npcdialog.h \
    bar.h \
    building.h \
    building2.h \
    building2floor.h \
    bullet.h \
    color_bar.h \
    ending.h \
    game.h \
    gameinfo.h \
    gameover1.h \
    gameover2.h \
    gray_bar.h \
    health.h \
    light.h \
    mini_image.h \
    money.h \
    nomal_bd.h \
    special_bd.h \
    summoner.h \
    taxi.h \
    taxi_distance.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
