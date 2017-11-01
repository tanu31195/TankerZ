#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T17:11:28
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TankerZ
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    button.cpp \
    mine.cpp \
    healthplus.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    player.h \
    score.h \
    health.h \
    button.h \
    mine.h \
    healthplus.h

RESOURCES += \
    resources.qrc
