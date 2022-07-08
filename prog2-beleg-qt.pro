QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbookdialog.cpp \
    addcddialog.cpp \
    adddvddialog.cpp \
    adduserdialog.cpp \
    book.cpp \
    borrowmediumdialog.cpp \
    cd.cpp \
    dvd.cpp \
    main.cpp \
    mainwindow.cpp \
    medium.cpp \
    mediumchoicedialog.cpp \
    user.cpp

HEADERS += \
    addbookdialog.h \
    addcddialog.h \
    adddvddialog.h \
    adduserdialog.h \
    book.h \
    borrowmediumdialog.h \
    cd.h \
    dvd.h \
    mainwindow.h \
    medium.h \
    mediumchoicedialog.h \
    user.h

FORMS += \
    addbookdialog.ui \
    addcddialog.ui \
    adddvddialog.ui \
    adduserdialog.ui \
    borrowmediumdialog.ui \
    mainwindow.ui \
    mediumchoicedialog.ui

TRANSLATIONS += \
    prog2-beleg-qt_de_DE.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
