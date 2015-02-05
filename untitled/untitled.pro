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
    testgame.cpp \
    Engine/gameobject.cpp \
    Engine/gameresourse.cpp \
    Engine/gamewindow.cpp \
    Engine/geometry.cpp \
    Engine/keyboard.cpp \
    Engine/mesh.cpp \
    Engine/mouse.cpp \
    Engine/shader.cpp \
    Engine/texture.cpp \
    testobject.cpp \
    Engine/transform.cpp

HEADERS  +=\
    testgame.h \
    Engine/gameobject.h \
    Engine/gameresourse.h \
    Engine/gamewindow.h \
    Engine/geometry.h \
    Engine/keyboard.h \
    Engine/map.h \
    Engine/mesh.h \
    Engine/mouse.h \
    Engine/shader.h \
    Engine/texture.h \
    testobject.h \
    Engine/transform.h

FORMS    +=

OTHER_FILES += \
    Vertex.vsh \
    Frag.fsh

RESOURCES += \
    resources.qrc
