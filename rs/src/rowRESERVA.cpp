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

#include "rowRESERVA.h"
#include "CReservaList.h"

rowRESERVA::rowRESERVA ( Statement *stmt )
{
	if ( stmt )
	{
		Time ts;
		Date dt;
		int h, m, s, y, mo, d;
		std::string str;

		( *stmt )->Get ( 1, RESERVAID );
		( *stmt )->Get ( 2, SALAID ),

		( *stmt )->Get ( 3, dt );
		dt.GetDate ( y, mo, d );
		DATA = QDate ( y, mo, d );

		( *stmt )->Get ( 4, ts );
		ts.GetTime ( h, m, s );
		HORAIN = QTime ( h, m, s );

		( *stmt )->Get ( 5, ts );
		ts.GetTime ( h, m, s );
		HORAFIM = QTime ( h, m, s );

		( *stmt )->Get ( 6, USUARIOID );

		( *stmt )->Get ( 7, str );
		USUARIO = str.c_str();

		( *stmt )->Get ( 8, str );
		ASSUNTO = str.c_str();

		( *stmt )->Get ( 9, str );
		DEPTO = str.c_str();

		( *stmt )->Get ( 10, str );
		NOTAS = str.c_str();

		( *stmt )->Get ( 11, SCHEMEID );

		( *stmt )->Get ( 12, str );
		TIPO = *str.c_str();
	}
	else
	{
		RESERVAID = -1;
		SALAID = -1;
		USUARIOID = -1;
		SCHEMEID = -1;
	}
}

bool rowRESERVA::checkRow ( CReservaList* _list )
{
	return ( _list->m_salaID == SALAID ) &&
	       ( _list->m_date == DATA );
}
