QT += core
QT -= gui

TARGET = Hangman
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hangman.cpp

HEADERS += \
    hangman.h \
    loadfile.h

