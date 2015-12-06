#-------------------------------------------------
#
# Project created by QtCreator 2015-11-20T22:16:36
#
#-------------------------------------------------

QT       += core gui multimedia


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
    building.cpp \
    building2floor.cpp \
    bullet.cpp \
    color_bar.cpp \
    ending.cpp \
    game.cpp \
    gameinfo.cpp \
    gameover1.cpp \
    gameover2.cpp \
    gray_bar.cpp \
    light.cpp \
    mini_image.cpp \
    money.cpp \
    summoner.cpp \
    taxi.cpp \
    taxi_distance.cpp \
    rectangle.cpp \
    minigame.cpp \
    machugi.cpp \
    itembox.cpp \
    fail.cpp \
    explain.cpp \
    darkbed.cpp \
    background.cpp \
    message.cpp \
    bar.cpp \
    gamescene.cpp

HEADERS  += mainwindow.h \
    tile.h \
    character.h \
    map.h \
    mapdata.h \
    menustrip.h \
    npcdialog.h \
    building.h \
    building2floor.h \
    bullet.h \
    color_bar.h \
    ending.h \
    game.h \
    gameinfo.h \
    gameover1.h \
    gameover2.h \
    gray_bar.h \
    light.h \
    mini_image.h \
    money.h \
    summoner.h \
    taxi.h \
    taxi_distance.h \
    rectangle.h \
    minigame.h \
    machugi.h \
    itembox.h \
    fail.h \
    explain.h \
    darkbed.h \
    background.h \
    message.h \
    bar.h \
    building2.h \
    gamescene.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
