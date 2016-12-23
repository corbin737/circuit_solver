TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    matrix.c \
    circuit.c

HEADERS += \
    matrix.h \
    circuit.h

DISTFILES += \
    input.txt
