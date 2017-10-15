#-------------------------------------------------
#
# Project created by QtCreator 2017-10-12T21:46:44
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FruitManageSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_NO_DEBUG_OUTPUT
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DialogInsert.cpp \
    DBHelper.cpp \
    Fruit.cpp \
    FruitDao.cpp \
    FruitDaoImp.cpp \
    DialogDelete.cpp \
    DialogUpdate.cpp \
    DialogSelect.cpp

HEADERS += \
        MainWindow.h \
    DialogInsert.h \
    DBHelper.h \
    Fruit.h \
    FruitDao.h \
    FruitDaoImp.h \
    DialogDelete.h \
    DialogUpdate.h \
    DialogSelect.h

FORMS += \
        MainWindow.ui \
    DialogInsert.ui \
    DialogDelete.ui \
    DialogUpdate.ui \
    DialogSelect.ui

RESOURCES += \
    fruit.qrc
RC_FILE = myapp.rc
