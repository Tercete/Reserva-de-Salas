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
 
#include "CEsquemaComboBox.h"
#include "CSchemasModel.h"

#include <QPainter>
#include <QPalette>

CEsquemaDelegate::CEsquemaDelegate( CData * _data, QObject * parent ):
	QAbstractItemDelegate( parent ),
	m_data( _data )
{
}

QSize CEsquemaDelegate::sizeHint(const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
	QString text = tr("Esquema ") + index.data(Qt::DisplayRole).toString();
	QFontMetrics fontMetrics(option.font);
	return QSize( fontMetrics.width(text), fontMetrics.lineSpacing() * 1.5 );
}


void CEsquemaDelegate::paint(QPainter *painter,
								const QStyleOptionViewItem &option,
								const QModelIndex &index) const
{
	QString text = tr("Esquema ") + index.data(Qt::DisplayRole).toString();

	QRect r = option.rect;

	if (option.state & QStyle::State_Selected)
	{
		painter->save();
		painter->setBrush(option.palette.highlight());
		painter->setPen(Qt::NoPen);
		painter->drawRect(option.rect);
		painter->setPen(QPen(option.palette.highlightedText(), 0));
	}
	else
	{
		painter->save();
		
		QPalette * palette = m_data->getColorScheme( index.data(Qt::DisplayRole).toInt() );
		
		painter->setBrush( palette->brush(QPalette::Base) );
		painter->setPen(Qt::NoPen);
		painter->drawRect(option.rect);
		painter->setPen(QPen(palette->brush(QPalette::Text), 0));
	}
	painter->drawText(r, Qt::AlignVCenter|Qt::AlignLeading|Qt::TextSingleLine, text);


	if (option.state & QStyle::State_Selected)
		painter->restore();
}


CEsquemaComboBox::CEsquemaComboBox( CData * _data, QWidget * parent ):
	QComboBox( parent )
{
	CSchemasModel model( _data );
	
	for ( int i = 0; i < model.rowCount(); ++i )
	{
		addItem( model.headerData( i, Qt::Vertical ).toString() );
	}
	
	setItemDelegate( new CEsquemaDelegate( _data, this ));
}

CEsquemaComboBox::~CEsquemaComboBox()
{
}
