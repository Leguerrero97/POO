QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginApp
TEMPLATE = app

SOURCES += main.cpp \
           login.cpp \
           ventana.cpp

HEADERS += login.h \
           ventana.h

FORMS += ventana.ui
