#-------------------------------------------------
#
# Project created by QtCreator 2024-05-07T10:56:33
#
#-------------------------------------------------

QT += core gui network
CONFIG += c++11 #console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YouthStudy
TEMPLATE = app
#添加logo
RC_ICONS = logo.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        editlist.cpp \
        incomplistwidget.cpp \
        login.cpp \
        main.cpp \
        mainwidget.cpp \
        user.cpp

HEADERS += \
        editlist.h \
        incomplistwidget.h \
        login.h \
        mainwidget.h \
        user.h

FORMS += \
        editlist.ui \
        incomplistwidget.ui \
        login.ui \
        mainwidget.ui \
        user.ui

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./QXlsx/         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./QXlsx/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./QXlsx/source/  # current QXlsx source path is ./source/
include(./QXlsx/QXlsx.pri)


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
