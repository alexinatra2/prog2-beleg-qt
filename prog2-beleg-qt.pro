QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmediumdialog.cpp \
    adduserdialog.cpp \
    blueray.cpp \
    book.cpp \
    borrowdialog.cpp \
    cd.cpp \
    dvd.cpp \
    main.cpp \
    mainwindow.cpp \
    medium.cpp \
    user.cpp \
    videomedium.cpp

HEADERS += \
    addmediumdialog.h \
    adduserdialog.h \
    blueray.h \
    book.h \
    borrowdialog.h \
    cd.h \
    dvd.h \
    mainwindow.h \
    medium.h \
    user.h \
    videomedium.h

FORMS += \
    addmediumdialog.ui \
    adduserdialog.ui \
    borrowdialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    prog2-beleg-qt_de_DE.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
