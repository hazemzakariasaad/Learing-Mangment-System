QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createcourse.cpp \
    createprofessor.cpp \
    createstudent.cpp \
    editcourse.cpp \
    editprofessor.cpp \
    editstudent.cpp \
    main.cpp \
    admin.cpp   \
    classes.cpp \
    mainmenu.cpp

HEADERS += \
    admin.h \
    classes.h \
    createcourse.h \
    createprofessor.h \
    createstudent.h \
    editcourse.h \
    editprofessor.h \
    Database.h \
    editstudent.h \
    mainmenu.h

FORMS += \
    admin.ui \
    createcourse.ui \
    createprofessor.ui \
    createstudent.ui \
    editcourse.ui \
    editprofessor.ui \
    editstudent.ui \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
