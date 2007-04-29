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

#ifndef __INCLUDE_CMODELOSITEM_H
#define __INCLUDE_CMODELOSITEM_H

#include "CData.h"
#include "../obj/ui_frmodelositem.h"

class CModelos;

class CModelosItem: public QDialog, public Ui::ModeloItem
{
		Q_OBJECT

	public:
		CModelosItem ( Database _db, CModelos *_owner );
		~CModelosItem();

	private:
		Database	m_db;
		int			m_ModeloID;
		CModelos	*m_owner;

	public:
		void setModeloID ( const int _value ) {m_ModeloID = _value;};

	public slots:
		void onAccept();
};

#endif //__INCLUDE_CMODELOSITEM_H
