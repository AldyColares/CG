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
    cubeScenario.cpp \
    loadmaterial.cpp \
    crossproduct.cpp \
    unitvector.cpp \
    scenarioobject.cpp \
    dot.cpp \
    generatevetor.cpp \
    opglscenerio.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    cubeScenario.h \
    loadmaterial.h \
    crossproduct.h \
    unitvector.h \
    scenarioobject.h \
    dot.h \
    face3d.h \
    point3d.h \
    propertymaterial.h \
    generatevetor.h \
    opglscenerio.h

FORMS    += mainwindow.ui

LIBS +=  -lGLU
