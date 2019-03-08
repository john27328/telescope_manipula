#-------------------------------------------------
#
# Project created by QtCreator 2017-02-16T09:00:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = manipula4
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mtr.cpp \
    optmtr.cpp \
    grafsouce.cpp \
    grafwidget.cpp

HEADERS  += widget.h \
    mtr.h \
    optmtr.h \
    grafwidget.h \
    grafsource.h

FORMS    += widget.ui
