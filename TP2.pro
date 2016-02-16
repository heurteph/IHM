#-------------------------------------------------
#
# Project created by QtCreator 2016-02-02T11:23:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    zonedessin.cpp \
    stroke.cpp \
    rectangle.cpp \
    ellipse.cpp

HEADERS  += mainwindow.h \
    zonedessin.h \
    stroke.h \
    rectangle.h \
    ellipse.h

FORMS    += mainwindow.ui

RESOURCES += \
    ResourcesFile.qrc
