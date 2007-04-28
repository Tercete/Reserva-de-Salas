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
#ifndef __INCLUDE_CRESERVALIST_H
#define __INCLUDE_CRESERVALIST_H

#include "CData.h"
#include "CSalaList.h"
#include "CMainWindow.h"
#include "CReserva.h"

#include <QFrame>
#include <QLayout>
#include <QLabel>
#include <QPainter>

class rowRESERVA;
class CReserva;
class CSemana;
class CReservaList: public QFrame
{
	Q_OBJECT
	
	private:
		CSemana		*m_owner;
		QDate		m_date;
		int			m_salaID;
		QPoint		m_position;
		
		QGridLayout *gridLayout;
		QVBoxLayout *vboxLayout;
		
	protected:
		virtual void mouseDoubleClickEvent(QMouseEvent * event);
		virtual void mousePressEvent(QMouseEvent * event);
		
	public:
		CReservaList(CSemana *_owner, QDate _date, int _salaID);
		~CReservaList();
		
		bool loadList(rowRESERVA* _row);
	
		TListaReserva	m_reservas;
		CReserva*	addReserva();
		void insertReserva(CReserva* _reserva);
	
		int	getSALAID() {return m_salaID;};
		QDate	getDATA() {return m_date;};
	
		friend class CReserva;
		friend class rowRESERVA;

		void setPosition( const QPoint _value ) { m_position = _value; };
		QPoint getPosition() const { return m_position; };

	signals:
		void showReservaMenu(const QPoint _pos);
};

#endif
