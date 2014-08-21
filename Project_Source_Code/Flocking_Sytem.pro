#-------------------------------------------------
#
# Project created by QtCreator 2011-04-01T19:48:38
#
#-------------------------------------------------

QT += opengl
QT += core \
        gui \
        xml


TARGET = bin/Flocking_Sytem
TEMPLATE = app
DESTDIR=./
# this is where we want to put the intermediate build files ( .o)
OBJECTS_DIR=./obj/
MOC_DIR=./moc/

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/GLWindow.cpp \
        src/Boid.cpp \
        src/Flock.cpp


INCLUDEPATH+=./include

HEADERS  +=include/mainwindow.h\
           include/GLWindow.h \
           include/Boid.h \
           include/Flock.h

FORMS    += mainwindow.ui

OTHER_FILES+= shaders/Fragment.fs \
              shaders/Vertex.vs \
              shaders/Colour.fs \
              shaders/Colour.vs

CONFIG += console
CONFIG -= app_bundle

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
macx:INCLUDEPATH+=/usr/local/boost/
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native
# define the _DEBUG flag for the graphics lib
DEFINES +=NGL_DEBUG

LIBS += -L/usr/local/lib
# add the ngl lib
LIBS +=  -L/$(HOME)/NGL/lib -l NGL

# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-g++:linux-g++-64 {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
linux-g++ {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
DEPENDPATH+=include
# if we are on a mac define DARWIN
macx:DEFINES += DARWIN
# this is where to look for includes
INCLUDEPATH += $$(HOME)/NGL/include/

win32: {
        DEFINES+=USING_GLEW
        INCLUDEPATH+=-I c:/boost_1_44_0
        INCLUDEPATH+= -I C:/NGL/Support/glew
        LIBS+= -L C:/NGL/lib
        LIBS+= -lmingw32
}
