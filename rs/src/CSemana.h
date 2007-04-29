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
#ifndef __INCLUDE_CSEMANA_H
#define __INCLUDE_CSEMANA_H

#include "CData.h"
#include "CSalaList.h"
#include "CMainWindow.h"
#include "CReserva.h"
#include "rowRESERVA.h"

#include <QDate>

class CReservaList;

class CSemana: public QObject
{
		Q_OBJECT

		friend class CReservaList;
		friend class CReserva;

	public:
		CSemana ( CMainWindow *_parent, QDate &_segunda, CData *_owner,
		          CSalaList *_salas, const int _areaId );
		~CSemana();

	private:
		CData			*m_owner;
		CSalaList		*m_salas;
		QDate			m_date;
		CMainWindow		*m_parent;
		int				m_areaId;

		typedef			QMap<int, CReserva*> TMapReservas;
		TMapReservas    m_reservaItems;

		Transaction		m_tr;
		Statement		m_stmt;
		rowRESERVA		m_row;
		void fetchRow();

		int				m_lastUpdate;

		typedef			QMap<int, CReservaList*> TSemanaListMap;
		typedef			QList<TSemanaListMap> TSemanaList;
		TSemanaList		m_reservas;

		CReservaList* m_firstReservaList;

	public:
		bool			loadData();
		void			clear();
		CReservaList*	getReservaList ( int _dow, int _salaID );
		CReservaList*	getFirstReservaList() {return m_firstReservaList;};

		int				getAreaId() {return m_areaId;};
		CData*			getOwner() { return m_owner; };
		CMainWindow*	getParent() { return m_parent; };

	public slots:
		void onFBEvent ( int event );
};

#endif

