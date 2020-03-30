QT += core gui
QT += widgets

TARGET = pokemoncard
TEMPLATE = app
CONFIG += c++11
CONFIG += qt
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = resources.qrc

SOURCES += \
    main.cpp \
    MODEL/allenatore.cpp \
    MODEL/carta.cpp \
    MODEL/energia.cpp \
    MODEL/pokemon.cpp \
    MODEL/cardbuilder.cpp \
    MODEL/jsonio.cpp \
    MODEL/model.cpp \
    MODEL/qfilterproxymodel.cpp \
    MODEL/qlistmodeladapter.cpp \
    GUI/mainwindow.cpp \
    GUI/tableview.cpp \
    GUI/cardeditor.cpp \
    GUI/pokemoneditor.cpp

HEADERS += \
    MODEL/allenatore.h \
    MODEL/carta.h \
    MODEL/energia.h \
    MODEL/pokemon.h \
    MODEL/container.h \
    MODEL/deepptr.h \
    MODEL/cardbuilder.h \
    MODEL/jsonio.h \
    MODEL/model.h \
    MODEL/qfilterproxymodel.h \
    MODEL/qlistmodeladapter.h \
    JSON/json.hpp \
    GUI/mainwindow.h \
    GUI/tableview.h \
    GUI/cardeditor.h \
    GUI/pokemoneditor.h
