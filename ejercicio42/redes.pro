#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T12:30:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = redes
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    computadora.cpp \
    router.cpp \
    tabla.cpp \
    rutas.cpp

HEADERS  += principal.h \
    computadora.h \
    router.h \
    tabla.h \
    rutas.h

FORMS    += principal.ui
