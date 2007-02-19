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
 
#ifndef CESQUEMACOMBOBOX_H_
#define CESQUEMACOMBOBOX_H_

#include "CData.h"
#include <QComboBox>

class CEsquemaComboBox: public QComboBox
{
	Q_OBJECT
	
	public:
		CEsquemaComboBox( CData * _data, QWidget * parent = 0 );
		virtual ~CEsquemaComboBox();
};

class CEsquemaDelegate : public QAbstractItemDelegate
{
	Q_OBJECT

	public:
		CEsquemaDelegate( CData * _data, QObject * parent );

	private:
		CData * m_data;
			
	public:
		// painting
		virtual void paint ( QPainter * painter, const QStyleOptionViewItem & option,
								const QModelIndex & index ) const;
				
		virtual QSize sizeHint ( const QStyleOptionViewItem & option,
									const QModelIndex & index ) const;
};

#endif /*CESQUEMACOMBOBOX_H_*/
