#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T15:13:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QDataWidgetMapper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    mapdelegate.cpp

HEADERS  += mainwindow.h \
    model.h \
    mapdelegate.h

FORMS    += mainwindow.ui
