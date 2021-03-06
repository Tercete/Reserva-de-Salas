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
         ui/frareas.ui \
         ui/frusersareas.ui
RESOURCES += res/rs.qrc
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
           CUsuarioDelegate.h \
           CDBSettings.h \
           CAreas.h \
           CAreasModel.h \
           CSalaList.h \
           CSala.h \
           CReservaList.h \
           CSemana.h \
           CReserva.h \
           rowRESERVA.h \
           CUsuariosAreas.h \
           CEsquemaComboBox.h
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
           CUsuarioDelegate.cpp \
           CDBSettings.cpp \
           CAreas.cpp \
           CAreasModel.cpp \
           CSalaList.cpp \
           CSala.cpp \
           CReservaList.cpp \
           CSemana.cpp \
           CReserva.cpp \
           rowRESERVA.cpp \
           CUsuariosAreas.cpp \
           CEsquemaComboBox.cpp
TRANSLATIONS +=	rs_en.ts \
		rs_ptBR.ts
RCC_DIR = $$OBJECTS_DIR
MOC_DIR = ../obj
UI_DIR = ../obj
OBJECTS_DIR = ../obj
DESTDIR = ../bin
CONFIG += qt \
exceptions \
warn_on \
debug
TEMPLATE = app

 CONFIG(debug, debug|release) {
     TARGET = rs.debug
 } else {
     TARGET = rs
 }

linux-g++ {
    DEFINES += IBPP_LINUX

    languages.path = /usr/local/share/rs
    for( translate, TRANSLATIONS ){
        fileName = $$system( echo $$translate | sed -e s/[.].*/.qm/ )

        languages.files += ../bin/$$fileName
        # This line just ensures that there is a file there so the Maketargets are built.
        system($(echo $QMAKE | sed -e s/qamke//)lrelease $$translate -qm ../bin/$$fileName )
    }

    binary.path = /usr/local/bin
    binary.files += ../bin/rs
    INSTALLS += binary languages
    CONFIG -= release

    LIBS += -L/usr/lib \
  -lfbclient

    OBJECTS_DIR = ../obj

    UI_DIR = ../obj

    MOC_DIR = ../obj

}
win32 {
    DEFINES += IBPP_WINDOWS
    RC_FILE = ./res/rs.rc
}
xwin32-g++ {
    DEFINES += IBPP_WINDOWS
    RC_FILE = ./res/rs.rc
}
macx {
	DEFINES += IBPP_DARWIN
	LIBS += /Library/Frameworks/Firebird.framework/Libraries/libfbclient.dylib

}
QT += core gui network widgets printsupport

INCLUDEPATH += ../ibpp
.
LIBS += ../obj/libibpp.a

TARGETDEPS += ../obj/libibpp.a

