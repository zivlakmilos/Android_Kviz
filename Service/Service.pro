QT		+= core gui
CONFIG	+=

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AndroidKviz
TEMPLATE = app

SOURCES	+= main.cpp

HEADERS +=

release:DESTDIR = release
release:OBJECTS_DIR = release/.obj
release:MOC_DIR = release/.moc
release:RCC_DIR = release/.rcc
release:UI_DIR = release/.ui

debug:DESTDIR = debug
debug:OBJECTS_DIR = debug/.obj
debug:MOC_DIR = debug/.moc
debug:RCC_DIR = debug/.rcc
debug:UI_DIR = debug/.ui
