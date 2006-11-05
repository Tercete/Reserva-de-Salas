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

#include "CComboBoxDelegate.h"
#include <QtGui/QComboBox>

CComboBoxDelegate::CComboBoxDelegate(QObject *_parent):
	QItemDelegate(_parent)
{
	
}

QWidget * CComboBoxDelegate::createEditor ( QWidget * parent, const QStyleOptionViewItem & option,
									const QModelIndex & index ) const
{
	if (index.column() == 5)
	{
		QComboBox *editor = new QComboBox(parent);
		
		editor->installEventFilter(const_cast<CComboBoxDelegate*>(this));
	
		QStringList stringList = index.model()->data(index, Qt::LookUpRole).toStringList();
		editor->addItems(stringList);

		return editor;
	}
	else
		return QItemDelegate::createEditor(parent, option, index);
}

void CComboBoxDelegate::setEditorData ( QWidget * editor, const QModelIndex & index ) const
{
	if (index.column() == 5)
	{
		QComboBox *comboBox = static_cast<QComboBox*>(editor);

		int listIndex = comboBox->findText( index.model()->data(index, Qt::DisplayRole).toString() );
		comboBox->setCurrentIndex(listIndex);
	}
	else
		QItemDelegate::setEditorData(editor, index);
}

void CComboBoxDelegate::setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
{
	if (index.column() == 5)
	{
		QComboBox *comboBox = static_cast<QComboBox*>(editor);

		model->setData(index, comboBox->currentText());
	}
	else
		QItemDelegate::setModelData(editor, model, index);
}

