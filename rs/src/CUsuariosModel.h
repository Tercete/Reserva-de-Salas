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

#ifndef __INCLUDE_CUSUARIO_MODEL_H
#define __INCLUDE_CUSUARIO_MODEL_H

#include "main.h"
#include "CData.h"

class CUsuariosModel : public QAbstractTableModel
{
	Q_OBJECT
	
	public:
		CUsuariosModel( CData* _data );
		virtual ~CUsuariosModel();
	
	private:
		CData			*m_data;
		Transaction		*m_tr;
		
		struct ROW_USUARIOS
		{
			int 	USUARIOID;
			QString	LOGIN;
			QString	NOME;
			QString	STYLE;
			int		SCHEMEID;
			int		NIVEL;
			QString	AREA;
		};
		typedef QList<ROW_USUARIOS*> TROW_USUARIOS;
		TROW_USUARIOS m_rows;
		
	public:
		void CommitData() {(*m_tr)->Commit();};
		CData*	getData() { return m_data; };

		virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
		virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
		virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

		virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
		
		virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
		virtual Qt::ItemFlags flags(const QModelIndex & index) const;
		
		virtual bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
		virtual bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
};

#endif //__INCLUDE_CUSUARIO_MODEL_H
