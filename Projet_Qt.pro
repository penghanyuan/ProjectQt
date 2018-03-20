#-------------------------------------------------
#
# Project created by QtCreator 2018-02-13T16:27:58
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    addperson.cpp \
    c_init_bd.cpp \
    connectionsql.cpp \
    models/account.cpp \
    models/appointment.cpp \
    models/client.cpp \
    models/resource.cpp \
    models/type.cpp \
    addclient.cpp \
    dao/clientdao.cpp \
    dao/resourcedao.cpp \
    dao/appointmentdao.cpp \
    dao/typedao.cpp \
    dao/accountdao.cpp \
    controller/accountcontroller.cpp \
    controller/resourcescontroller.cpp \
    controller/clientcontroller.cpp \
    controller/typecontroller.cpp \
    toolbox.cpp \
    cool.cpp \
    editclient.cpp \
    controller/appointmentcontroller.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    addclient.h \
    addperson.h \
    c_init_bd.h \
    connectionsql.h \
    models/account.h \
    models/appointment.h \
    models/client.h \
    models/resource.h \
    models/type.h \
    dao/clientdao.h \
    dao/resourcedao.h \
    dao/appointmentdao.h \
    dao/typedao.h \
    dao/accountdao.h \
    controller/accountcontroller.h \
    controller/resourcescontroller.h \
    controller/clientcontroller.h \
    controller/typecontroller.h \
    toolbox.h \
    cool.h \
    editclient.h \
    controller/appointmentcontroller.h

FORMS += \
        mainwindow.ui \
    login.ui \
    addclient.ui \
    addperson.ui \
    cool.ui \
    editclient.ui

RESOURCES += \
    icons.qrc
