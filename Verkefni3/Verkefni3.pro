#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T15:06:19
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Verkefni3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    connection.cpp \
    data.cpp \
    engine.cpp \
    scientist.cpp \
    displaywindow.cpp

HEADERS  += mainwindow.h \
    computer.h \
    connection.h \
    data.h \
    engine.h \
    scientist.h \
    globalstrings.h \
    displaywindow.h

FORMS    += mainwindow.ui \
    displaywindow.ui
