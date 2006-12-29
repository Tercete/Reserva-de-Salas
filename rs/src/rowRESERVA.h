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
#ifndef __INCLUDE_ROWRESERVA_H
#define __INCLUDE_ROWRESERVA_H


#include "main.h"

#include <ibpp.h>

class CReservaList;
class rowRESERVA
{
	public:
		int RESERVAID;
		int SALAID;
		QDate DATA;
		QTime HORAIN;
		QTime HORAFIM;
		int USUARIOID;
		QString USUARIO;
		QString ASSUNTO;
		QString DEPTO;
		QString NOTAS;
		int SCHEMEID;
		char TIPO;

		rowRESERVA(Statement *stmt);

		bool checkRow(CReservaList* _list);
};

#endif

