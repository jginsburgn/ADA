#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T21:02:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Computer Graphics"
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    painter.cpp \
    figure.cpp

HEADERS  += mainwindow.h \
    painter.h \
    figure.h

FORMS    += mainwindow.ui

CONFIG += c++11

INCLUDEPATH += "/Path/to/dir/containing/Helper.h/"
