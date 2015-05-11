#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T00:07:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EveryMusic
TEMPLATE = app

CONFIG += C++11

SOURCES += main.cpp\
        widget.cpp \
    MIDI/QtMIDI.cpp

HEADERS  += widget.h \
    MIDI/MIDI_Timbre.h \
    MIDI/QtMIDI.h

LIBS += "C:\\Program Files (x86)\\Windows Kits\\8.1\\Lib\\winv6.3\\um\\x86\\WinMM.Lib"
