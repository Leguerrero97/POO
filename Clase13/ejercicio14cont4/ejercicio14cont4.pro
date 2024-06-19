QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

HEADERS += \
    admindb.h \
    formulario.h \
    login.h

SOURCES += \
    admindb.cpp \
    login.cpp \
    formulario.cpp \
    main.cpp \
