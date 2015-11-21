#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T20:34:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Table And DB Sandbox"
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp

HEADERS  += mainwindow.h\
            Helper.h \
    model.h \
    GeneralQt.h \

FORMS    += mainwindow.ui

CONFIG += c++11

#Adding libraries for connecting to PostgreSQL
LIBS += /usr/local/Cellar/libpqxx/4.0.1/lib/libpqxx.a -lpq

#The line below is for including all headers of libpqxx.a
INCLUDEPATH += /usr/local/Cellar/libpqxx/4.0.1/include/

INCLUDEPATH += "/Users/MacBook/ADA/Tasks/Xcode ADA Workspace/"
INCLUDEPATH += /Users/MacBook/ADA/Tasks/Xcode\ ADA\ Workspace/
INCLUDEPATH += "../General Qt Code/"
INCLUDEPATH += ../General\ Qt\ Code/
