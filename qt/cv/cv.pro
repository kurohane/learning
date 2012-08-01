#-------------------------------------------------
#
# Project created by QtCreator 2012-07-23T16:46:22
#
#-------------------------------------------------

QT       += core gui

TARGET = cv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    convertimage.cpp \
    cvimage.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    convertimage.h \
    cvimage.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc
