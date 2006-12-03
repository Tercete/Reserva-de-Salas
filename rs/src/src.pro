# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src
# Target is an application:  rs

FORMS += ui/frmain.ui \
         ui/frmodelos.ui \
         ui/frmodelositem.ui \
         ui/frreserva.ui \
         ui/frsalas.ui \
         ui/frsalasitem.ui \
         ui/frschemas.ui \
         ui/frusers.ui \
         ui/itemreserva.ui \
         ui/listareservas.ui \
         ui/frdbsettings.ui \
         ui/frareas.ui 
HEADERS += CConfig.h \
           CData.h \
           CMainWindow.h \
           CModelos.h \
           CModelosItem.h \
           CNotification.h \
           CReservaItem.h \
           CSalas.h \
           CSalasItem.h \
           CSchemas.h \
           CSchemasModel.h \
           CUsuarios.h \
           CUsuariosModel.h \
           main.h \
           CComboBoxDelegate.h \
           CDBSettings.h \
           CAreas.h \
           CAreasModel.h 
SOURCES += CConfig.cpp \
           CData.cpp \
           CMainWindow.cpp \
           CModelos.cpp \
           CModelosItem.cpp \
           CNotification.cpp \
           CReservaItem.cpp \
           CSalas.cpp \
           CSalasItem.cpp \
           CSchemas.cpp \
           CSchemasModel.cpp \
           CUsuarios.cpp \
           CUsuariosModel.cpp \
           main.cpp \
           CComboBoxDelegate.cpp \
           CDBSettings.cpp \
           CAreas.cpp \
           CAreasModel.cpp 
RESOURCES = res/rs.qrc
RCC_DIR = $$OBJECTS_DIR
DEPENDPATH = .
INCLUDEPATH += ../ibpp \
.
MOC_DIR = ../obj
UI_DIR = ../obj
OBJECTS_DIR = ../obj
TARGET = rs
DESTDIR = ../bin
CONFIG += warn_off \
qt \
exceptions
TEMPLATE = app
LIBS += ../obj/libibpp.a
linux-g++{
  LIBS += /opt/firebird/lib/libfbclient.so
  DEFINES += IBPP_LINUX
}
win32{
  DEFINES += IBPP_WINDOWS
  RC_FILE = ./res/rs.rc
}
xwin32-g++{
  DEFINES += IBPP_WINDOWS
  RC_FILE = ./res/rs.rc
}
