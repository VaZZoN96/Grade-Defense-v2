TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    entity.cpp \
    tower.cpp \
    unit.cpp \
    base.cpp \
    player.cpp \
    map_tile.cpp \
    mapa.cpp \
    ui.cpp
INCLUDEPATH += "$$(onedrive)\QT\SFML-2.5.1/include"

LIBS += -L"$$(onedrive)\QT\SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    entity.h \
    tower.h \
    unit.h \
    base.h \
    player.h \
    map_tile.h \
    mapa.h \
    ui.h
