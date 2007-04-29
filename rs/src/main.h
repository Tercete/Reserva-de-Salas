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

#ifndef __INCLUDE_MAIN_H
#define __INCLUDE_MAIN_H

#include "CData.h"

#include <QtCore/Qt>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QList>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtCore/QAbstractTableModel>
#include <QtCore/QFile>
#include <QtCore/QSettings>
#include <iostream>

class CSalas;
class CMainWindow;

enum IntervalKind { ikWeekly, ikMonthly, ikCustom };

inline QApplication* app()
{
	return static_cast<QApplication*> ( QApplication::instance() );
}

namespace Qt
{
	static const int LookUpRole = UserRole + 1;
}

typedef QList<int> TIntList;

class CUpdateLock
{
	public:
		CUpdateLock ( QWidget *widget ) :
				m_widget ( widget )
		{
			m_widget->setUpdatesEnabled ( false );
		};

		~CUpdateLock()
		{
			m_widget->setUpdatesEnabled ( true );
			m_widget->update();
		};

	private:
		QWidget     *m_widget;
};

class CWaitCursor
{
	public:
		CWaitCursor()
		{
			app()->setOverrideCursor ( Qt::WaitCursor );
		};

		~CWaitCursor()
		{
			app()->restoreOverrideCursor();
		};
};

QSettings* getConfigFile();
void deleteConfigFile();

#endif // __INCLUDE_MAIN_H
