TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/funcoesGraficas.cpp \
        src/funcoesLogicas.cpp \
        src/main.cpp

HEADERS += \
    headers/funcoesGraficas.h \
    headers/funcoesLogicas.h

unix:!macx: LIBS += -lX11

unix:!macx: LIBS += -lSDL2

unix:!macx: LIBS += -lSDL2_mixer

unix:!macx: LIBS += -lSDL2_ttf

