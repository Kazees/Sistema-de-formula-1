QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lista.cpp \
    main.cpp \
    mainwindow.cpp \
    manipulararquivo.cpp \
    no.cpp \
    piloto.cpp

HEADERS += \
    lista.h \
    mainwindow.h \
    manipulararquivo.h \
    no.h \
    piloto.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \


DISTFILES += \
    ../icons8-logitech-50.png \
    ../icons8-razer-48.png \
    ../icons8-redragon-logo-48.png
