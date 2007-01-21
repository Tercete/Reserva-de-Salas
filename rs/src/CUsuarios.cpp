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

#include "CUsuarios.h"

#include <QFontMetrics>
#include <QHeaderView>

CUsuarios::CUsuarios(CData* _data):
	m_data(_data),
	m_model(0),
	m_delegate(0)
{
	setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	
	connect(this, SIGNAL(accepted()), this, SLOT(onAccept()));
		
	m_model = new CUsuariosModel( m_data );
	tableView->setModel( m_model );

	m_delegate = new CUsuarioDelegate( m_data, this );
	tableView->setItemDelegate( m_delegate );
	
	QFontMetrics fontMetrics( tableView->horizontalHeader()->font() );
	
	int width = 0;
	int x = 0;
	for (int i = 3; i < 5; ++i )
	{
		x = fontMetrics.width( m_model->headerData(i, Qt::Horizontal).toString() );
		if (x > width) width = x;
	}
	
	for (int i = 3; i < 5; ++i )
	{
		tableView->setColumnWidth( i, width + 10 );
	}
}

CUsuarios::~CUsuarios()
{
	if (m_model)
		delete m_model;

	if (m_delegate)
		delete m_delegate;
}

void CUsuarios::onAccept()
{
	m_model->CommitData();
}

void CUsuarios::on_pbRemover_clicked()
{
	QModelIndex index = tableView->selectionModel()->currentIndex();
	
	if (index.isValid())
	{
		
		QString usuario = m_model->data( m_model->index( index.row(), 0 )).toString();
		QString nome = m_model->data( m_model->index( index.row(), 1 )).toString();
		
		if ( nome.length() )
			usuario += " <i>(" + nome + ") </i>";
		
		if (! QMessageBox::question(
		    this,
		    tr("Excluir Usu�rio?"),
		    tr("Tem certeza que deseja excluir o usu�rio(a) %1?")
		    	.arg(usuario),
		    tr("&Sim"), tr("&N�o"),
		    QString(), 1, 0))
		{
			if (! QMessageBox::question(
			    this,
			    tr("Excluir Usu�rio?"),
			    tr("Isso ir� remover tamb�m todas as reservas feitas por %1, tem certeza <i>mesmo</i> que voc� quer fazer isso?")
			    	.arg(usuario),
			    tr("&Sim"), tr("&N�o"),
			    QString(), 1, 0))
			{
				m_model->removeRows(index.row(), 1);
			}
		}
	}
}
