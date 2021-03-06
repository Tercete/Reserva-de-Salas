; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "Reserva de Salas - Servidor"
!define PRODUCT_VERSION "1.0.6"
!define PRODUCT_PUBLISHER "RolTramInfo"
!define PRODUCT_WEB_SITE "http://reservadesalas.sourceforge.net"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\Firebird-2.0.0.12748-0-Win32.exe"
!define FIREBIRD_REGKEY "Software\Firebird Project\Firebird Server\Instances"

SetCompressor bzip2

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE ".\src\res\GPL-pt_BR.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!insertmacro MUI_PAGE_FINISH

; Language files
!insertmacro MUI_LANGUAGE "English"

; Reserve files
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "bin\rs-${PRODUCT_VERSION}-server-install.exe"
InstallDir "$TEMP"
ShowInstDetails show

Section "MainSection" SEC01
  SetOutPath "$TEMP"
  SetOverwrite ifnewer
  File ".\dist\Firebird-2.0.0.12748-0-Win32.exe"
  File "db\rs.sql"
  ExecWait "$INSTDIR\Firebird-2.0.0.12748-0-Win32.exe"
  ReadRegStr $0 HKLM "${FIREBIRD_REGKEY}" DefaultInstance
  
  FileOpen $1 "$0\aliases.conf" a ;Opens a Empty File an fills it
  FileSeek $1 0 END
  FileWrite $1 "$\r$\nRS = $0\rs.fdb$\r$\n"
  FileClose $1 ;Closes the filled file

  ExecWait "$0\bin\gsec.exe -user SYSDBA -password masterkey -add RS -pw rs"

  ExecWait "$0\bin\isql.exe -i $TEMP\rs.sql -u SYSDBA -p masterkey"
SectionEnd

Section -Post
SectionEnd