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

#include "CNotification.h"
#include <QtCore/QTimer>

CNotification::CNotification( QObject * _parent ):
	QObject( _parent ),
	m_ignoreCount(0)
{
	// Async Events got deprecated in IBPP
	#ifndef __ASYNC_EVENTS
	m_timer.setInterval(500);
	if (! connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimer())))
		throw -1;
		
	m_timer.start();
	#endif
}

void CNotification::ibppEventHandler(IBPP::Events _events,
	const std::string& _eventName, int _count)
{
	#ifdef __ASYNC_EVENTS
	{ //  <-Scope delimiter for MutexLocker
		QMutexLocker locker(&m_mutex);
	#endif
		if (m_ignoreCount)
		{
			--m_ignoreCount;
			return;
		}
	#ifdef __ASYNC_EVENTS
	} //  <-End scope delimiter for MutexLocker
	#endif
	
	FBEventType type = FBEUnknown;
	
	if (_eventName == "reserva_ins")
		type = FBEInsert;
	else if (_eventName == "reserva_upd")
		type = FBEUpdate;
	else if (_eventName == "reserva_del")
		type = FBEDelete;
	
	emit FBEvent( type );
}

void CNotification::incIgnoreCount()
{
	#ifdef __ASYNC_EVENTS
	QMutexLocker locker(&m_mutex);
	#endif
	++m_ignoreCount;
}


void CNotification::onTimer()
{
	#ifndef __ASYNC_EVENTS
	m_event->Dispatch();
	#endif
}
