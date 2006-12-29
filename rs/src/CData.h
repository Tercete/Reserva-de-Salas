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

#ifndef __INCLUDE_CDATA_H
#define __INCLUDE_CDATA_H

#include <ibpp.h>
#include <QtCore/QList>
#include <QtCore/QHash>
#include <QtCore/QString>
#include <QtGui/QPalette>
#include <QtCore/QDate>
#include <QtCore/QTime>


#include "CNotification.h"

using namespace IBPP;

Timestamp DateTimeToTimestamp(QDate _date, QTime _time);
QDate TimestampToDate(Timestamp _timestamp);

typedef QHash<int, QPalette*> TColorSchemeList;

class CMainWindow;
class CData: public QObject
{
	Q_OBJECT
	
	friend class CSalaList;
	friend class CSemana;

	public:
		CData();
		~CData();
	
	private:
		TColorSchemeList	m_colorSchemes;
		QStringList*		m_areas;
		QList<int>*			m_areasId;
		
		void loadColorSchemes();

	public:
		Database		m_db;
		CNotification*	m_notify;
		Events			m_event;

		bool connect();
		void disconnect();
		
		QPalette*		getColorScheme(int _id) { return m_colorSchemes[_id]; };
		QStringList*	getAreas();
		QStringList*	refreshAreas();
		int				getAreaId(const int _areaListIndex);
		int				getAreaId(const QString &_area) {return getAreaId(getAreas()->indexOf(_area)); };
};

#endif // __INCLUDE_CDATA_H

