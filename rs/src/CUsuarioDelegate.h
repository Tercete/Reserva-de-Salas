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

#ifndef CCOMBOBOXDELEGATE_H
#define CCOMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QAbstractItemView>

#include "main.h"
#include "CData.h"

/**
	@author Gianni Rossi <gianni.rossi@gmail.com>
*/
class CUsuarioDelegate: public QItemDelegate
{
		Q_OBJECT

	public:
		CUsuarioDelegate ( CData * _data, QObject *_parent = 0 );

	private:
		QStringList		* m_items;
		CData 			* m_data;

	public:
		virtual QWidget * createEditor ( QWidget * parent, const QStyleOptionViewItem & option,
		                                 const QModelIndex & index ) const;

		virtual void setEditorData ( QWidget * editor, const QModelIndex & index ) const;
		virtual void setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
};

#endif
