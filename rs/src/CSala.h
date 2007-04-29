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
#ifndef __INCLUDE_CSALA_H
#define __INCLUDE_CSALA_H

#include "CSalaList.h"
#include "CData.h"

class CSala
{
		friend class CSalaList;

	private:
		CSalaList   *m_owner;
		CSala ( CSalaList *_owner );

	public:
		~CSala();

	private:
		int		SALAID;
		int		oldSALAID;

		int		ANDAR;
		QString	NOME;
		QString	AREA;
	public:
		bool	save();
		bool	del();

		int getOldSalaID() {return oldSALAID;};
		int getSalaID() {return SALAID;};
		void setSalaID ( const int _salaID );
		int getAndar() {return ANDAR;};
		void setAndar ( const int _andar ) {ANDAR = _andar;};
		QString getNome() {return NOME;};
		void setNome ( const QString &_nome ) {NOME = _nome;};
		QString getArea() {return AREA;};
		void setArea ( const QString &_area ) {AREA = _area;};

		CSalaList* getOwner() {return m_owner;};

		int m_column;
};
typedef CSala* PSala;

#endif
