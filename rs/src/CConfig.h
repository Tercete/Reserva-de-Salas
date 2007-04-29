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

#ifndef __INCLUDE_CCONFIG_H
#define __INCLUDE_CCONFIG_H

#include "main.h"
#include "CData.h"

class CConfig
{
	public:
		~CConfig();

		int getUsuarioID();
		int getNivel();

		QString getStyle();
		void setStyle ( QString _value );

		QString	getLastArea();
		void	setLastArea ( const QString &_area );

		int getColorScheme();

		QString getUserName() {return m_userName;};

		static CConfig* getConfig ( CData *_data );
		static CConfig* getConfig();

		const TIntList* getUserSalaList() {return &m_userSalaList;};
		int getUserAreaID() {return m_userArea;};

		void setIntervalKind ( const IntervalKind& theValue );
		IntervalKind getIntervalKind() const;

		void setDayInterval ( int theValue );
		int getDayInterval() const;

	private:
		CConfig ( CData *_data );

		CData		*m_data;

		bool		m_loaded;
		void		loadConfig();

		QString		m_userName;
		int			m_userID;
		int			m_userNivel;
		QString		m_style;
		int			m_colorScheme;
		TIntList	m_userSalaList;
		int			m_userArea;
		IntervalKind m_intervalKind;
		int			m_dayInterval;
};

#endif // __INCLUDE_CCONFIG_H
