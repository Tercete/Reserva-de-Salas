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

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
	g_application = &app;

	QString locale;

	{
		QSettings settings("RolTram", "RS");
		settings.beginGroup("Locale");
		
		if ( settings.contains("Locale") )
			locale = settings.value("Locale").toString();
		else
			locale = QLocale::system().name();
	}
	
	QTranslator translator;

	translator.load(QString("rs_") + locale);
	app.installTranslator(&translator);
	
	int exitCode = -1;
	
	CMainWindow mainwindow;
	
	if ( mainwindow.initialize() )
	{
		{
			QSettings settings("RolTram", "RS");
			settings.beginGroup("mainwindow");

			if (settings.contains("maxed") && (settings.value("maxed") == true))
				mainwindow.setWindowState(Qt::WindowMaximized);
			else
			{
				if (settings.contains("size"))
					mainwindow.resize(settings.value("size").toSize());
			}
		}
		
		mainwindow.show();
	
		exitCode = app.exec();	
		
		{
			QSettings settings("RolTram", "RS");
			settings.beginGroup("mainwindow");
			
			if (mainwindow.windowState() == Qt::WindowMaximized)
				settings.setValue("maxed", true);
			else
			{
				settings.setValue("maxed", false);
				settings.setValue("size", mainwindow.size());
			}
		}
	}
		
	return exitCode;
}
