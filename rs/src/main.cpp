/*
	Reserva de Salas
	Copyright 2006 Gianfranco Rossi.

	Este programa � software livre; voc� pode redistribu�-lo e/ou
	modific�-lo sob os termos da Licen�a P�blica Geral GNU, conforme
	publicada pela Free Software Foundation; tanto a vers�o 2 da
	Licen�a.

	Este programa � distribu�do na expectativa de ser �til, mas SEM
	QUALQUER GARANTIA; sem mesmo a garantia impl�cita de
	COMERCIALIZA��O ou de ADEQUA��O A QUALQUER PROP�SITO EM
	PARTICULAR. Consulte a Licen�a P�blica Geral GNU para obter mais
	detalhes.

	Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU
	junto com este programa; se n�o, escreva para a Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
	02111-1307, USA.
 */

#include "main.h"
#include "CMainWindow.h"
#include <QSettings>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QFileInfo>

static QSettings* globalSettings = 0;

QSettings* getConfigFile()
{
	if ( ! globalSettings )
	{
		if ( QFile::exists ( "./Conf/RS.ini" ) )
		{
			QSettings::setPath ( QSettings::IniFormat, QSettings::SystemScope, "." );
			globalSettings = new QSettings ( QSettings::IniFormat, QSettings::SystemScope, "Conf","RS" );
		}
		else
		{
			QString path;
			QStringList searchPaths;
#ifdef __unix__
			searchPaths << "/etc/rs.conf" << "/etc/rs/rs.conf" << "/etc/xdg/rs.conf" << "/etc/xdg/rs/rs.conf"
			<< "../etc/rs.conf" << "./config/rs.conf" << "/usr/share/rs/rs.conf"
			<< "/usr/local/etc/rs.conf" << "/usr/local/etc/rs/rs.conf"
			<< QDir::home().path() + "/.config/rs/rs.conf" << QDir::home().path() + "/.config/RolTram/RS.conf";
#else
			searchPaths << "c:/etc/rs.conf" << "c:/etc/rs/rs.conf"
			<< "../etc/rs.conf" << "./config/rs.conf" << "c:/usr/share/rs/rs.conf"
			<< "c:/usr/local/etc/rs.conf" << "c:/usr/local/etc/rs/rs.conf"
			<< QDir::home().path() + "/.config/rs/rs.conf" << QDir::home().path() + "/.config/RolTram/RS.conf";
#endif

			for ( int i = 0; i < searchPaths.count(); ++i )
			{
				path = searchPaths[i];

				if ( QFileInfo ( path ).exists() )
				{
					path = searchPaths[i];
					goto FOUND;
				}
			}
#ifdef __unix__
			for ( int i = 0; i < searchPaths.count(); ++i )
			{
				QFileInfo fileInfo = QFileInfo ( searchPaths[i] );

				if ( QFileInfo ( fileInfo.path() ).isWritable() )
				{
					path = searchPaths[i];
					goto FOUND;
				}
			}

			path =  QDir::tempPath () + QDir::separator ()  + "rs.conf";
#else
			globalSettings = new QSettings ( QSettings::SystemScope, "RolTram", "RS" );
			return globalSettings;
#endif
		FOUND:
		globalSettings = new QSettings ( path, QSettings::NativeFormat );
		}
	}
	return globalSettings;
}

void deleteConfigFile()
{
	delete globalSettings;
	globalSettings = 0;
}


int main ( int argc, char *argv[] )
{
	QApplication app ( argc, argv );

	QString locale;

	{
		QSettings settings ( "RolTram", "RS" );
		settings.beginGroup ( "Locale" );

		if ( settings.contains ( "Locale" ) )
			locale = settings.value ( "Locale" ).toString();
		else
			locale = QLocale::system().name();
	}

	QTranslator translator;

	if ( locale != "pt_BR" )
	{
		QString localeFileName = QString ( "rs_" ) + locale + ".qm";
		
		QStringList searchPaths;
		searchPaths << QDir::toNativeSeparators ( app.applicationDirPath() + QDir::separator() )
#ifdef __unix__
					<< "../share/" << "/usr/share/rs/" << "/usr/local/share/rs/"
					<< "/usr/share/" << "/usr/local/share/";
#else
					<< "../share/" << "C:/usr/share/rs/" << "C:/usr/local/share/rs/"
					<< "C:/usr/share/" << "C:/usr/local/share/";
#endif

		for ( int i = 0; i < searchPaths.count(); ++i )
		{ 
			if ( QFileInfo ( searchPaths[i] + localeFileName ).exists() )
			{
				localeFileName = searchPaths[i] + localeFileName;
				goto FOUND;
			}
		}

		FOUND:
		if ( translator.load ( localeFileName ) )
			app.installTranslator ( &translator );
		else
			QMessageBox ( "Erro", "Unable to find language file: " + localeFileName, QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
	}

	int exitCode = -1;

	CMainWindow mainwindow;

	if ( mainwindow.initialize() )
	{
		{
			QSettings settings ( "RolTram", "RS" );
			settings.beginGroup ( "mainwindow" );

			if ( settings.contains ( "maxed" ) && ( settings.value ( "maxed" ) == true ) )
				mainwindow.setWindowState ( Qt::WindowMaximized );
			else
			{
				if ( settings.contains ( "size" ) )
					mainwindow.resize ( settings.value ( "size" ).toSize() );
			}
		}

		mainwindow.show();

		exitCode = app.exec();

		{
			QSettings settings ( "RolTram", "RS" );
			settings.beginGroup ( "mainwindow" );

			if ( mainwindow.windowState() == Qt::WindowMaximized )
				settings.setValue ( "maxed", true );
			else
			{
				settings.setValue ( "maxed", false );
				settings.setValue ( "size", mainwindow.size() );
			}
		}
	}

	return exitCode;
}
