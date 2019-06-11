#-------------------------------------------------
#
# Project created by QtCreator 2019-05-15T22:13:42
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myChat
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

CONFIG += c++11

SOURCES += \
        chatroom.cpp \
        client.cpp \
        connect.cpp \
        create.cpp \
        create_connect.cpp \
        main.cpp \
        mychat.cpp \
        mymessage.cpp \
        registration_form.cpp \
        signin_signup.cpp

HEADERS += \
        chatroom.h \
        client.h \
        connect.h \
        create.h \
        create_connect.h \
        mychat.h \
        mymessage.h \
        registration_form.h \
        signin_signup.h

FORMS += \
        chatroom.ui \
        connect.ui \
        create.ui \
        create_connect.ui \
        mychat.ui \
        myclient.ui \
        registration_form.ui \
        signin_signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
