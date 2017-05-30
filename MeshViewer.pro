#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T20:06:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MeshViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    openglwindow.cpp \
    modelmanager.cpp

HEADERS  += mainwindow.h \
    openglwindow.h \
    modelmanager.h

FORMS    += mainwindow.ui

unix:!macx|win32: LIBS += -L$$PWD/../../Assimp/assimp_vs2015/assimp_vs2015/lib/ -lassimp

INCLUDEPATH += $$PWD/../../Assimp/assimp_vs2015/assimp_vs2015/include
DEPENDPATH += $$PWD/../../Assimp/assimp_vs2015/assimp_vs2015/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp_vs2015/assimp_vs2015/lib/assimp.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp_vs2015/assimp_vs2015/lib/libassimp.a

unix:!macx|win32: LIBS += -L$$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/ -lDevIL

INCLUDEPATH += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/include
DEPENDPATH += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/DevIL.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/libDevIL.a

unix:!macx|win32: LIBS += -L$$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/ -lILU

INCLUDEPATH += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/include
DEPENDPATH += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/ILU.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/libILU.a

unix:!macx|win32: LIBS += -L$$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/ -lILUT

INCLUDEPATH += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/include
DEPENDPATH += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/ILUT.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/../../Assimp/assimp-3.3.1/samples/DevIL/lib/libILUT.a
