#-------------------------------------------------
#
# Project created by QtCreator 2014-12-21T14:06:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
    keyboard.cpp \
    mouse.cpp \
    gamewindow.cpp \
    testgame.cpp \
    texture.cpp \
    shader.cpp \
    mesh.cpp \
    geometry.cpp

HEADERS  += \
    keyboard.h \
    mouse.h \
    gamewindow.h \
    testgame.h \
    texture.h \
    shader.h \
    mesh.h \
    geometry.h

FORMS    +=

OTHER_FILES += \
    Vertex.vsh \
    Frag.fsh

RESOURCES += \
    resources.qrc
