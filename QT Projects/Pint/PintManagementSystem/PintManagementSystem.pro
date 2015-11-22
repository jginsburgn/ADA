#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T04:13:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Pint MS"
TEMPLATE = app

SOURCES += main.cpp\
        loginwindow.cpp \
    mainmenu.cpp \
    query.cpp \
    addcustomerwindow.cpp \
    addcustomeraddlocation.cpp \
    addcustomeraddlocationaddcontact.cpp \
    addcustomeraddlocationaddcontactaddphone.cpp \
    addcustomeraddlocationaddcontactaddemail.cpp \
    tablemodel.cpp

HEADERS  += loginwindow.h\
            Helper.h\
            GeneralQt.h \
    mainmenu.h \
    pintgd.h \
    query.h \
    addcustomerwindow.h \
    addcustomeraddlocation.h \
    addcustomeraddlocationaddcontact.h \
    addcustomeraddlocationaddcontactaddphone.h \
    addcustomeraddlocationaddcontactaddemail.h \
    tablemodel.h

FORMS    += loginwindow.ui \
    mainmenu.ui \
    addcustomerwindow.ui \
    addcustomeraddlocation.ui \
    addcustomeraddlocationaddcontact.ui \
    addcustomeraddlocationaddcontactaddphone.ui \
    addcustomeraddlocationaddcontactaddemail.ui

CONFIG += c++11

#Adding libraries for connecting to PostgreSQL
LIBS += /usr/local/Cellar/libpqxx/4.0.1/lib/libpqxx.a -lpq

#The line below is for including all headers of libpqxx.a
INCLUDEPATH += /usr/local/Cellar/libpqxx/4.0.1/include/

#This is for the Helper.h
INCLUDEPATH += "/Users/MacBook/ADA/Tasks/Xcode ADA Workspace/"
INCLUDEPATH += /Users/MacBook/ADA/Tasks/Xcode\ ADA\ Workspace/

#This is for the GeneralQt.h
INCLUDEPATH += "../../General Qt Code/"
INCLUDEPATH += ../../General\ Qt\ Code/
