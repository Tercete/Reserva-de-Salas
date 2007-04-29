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
#ifndef __INCLUDE_CSALALIST_H
#define __INCLUDE_CSALALIST_H

#include "CData.h"

#include <ibpp.h>

#include <QtCore/QMap>

class CSala;

class CSalaList
{
	private:
		CData   		*m_owner;
		Transaction 	*m_tr;
		int				m_areaId;

	public:
		CSalaList ( CData *_owner, const int _areaId = -1 );
		~CSalaList();

		void save();

		Transaction* getTransaction() {return m_tr;};

		typedef QMap<int, CSala*> TSalaList;
		bool loadList();

		TSalaList   m_salas;
		CSala* addSala();

		friend class CSala;
};

#endif
