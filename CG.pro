#-------------------------------------------------
#
# Project created by QtCreator 2016-10-13T20:31:12
#
#-------------------------------------------------

QT       += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    PineTree.cpp \
    cubeScenario.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    axis.h \
    PineTree.h \
    cubeScenario.h

FORMS    += mainwindow.ui

LIBS += -glut
