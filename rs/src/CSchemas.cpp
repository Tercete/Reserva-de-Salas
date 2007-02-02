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

#include "CSchemas.h"

CSchemas::CSchemas( CData* _data, QWidget * _parent ):
	QDialog( _parent ),
	m_data( _data ),
	m_model( 0 )
{
	setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	
	connect(this, SIGNAL(accepted()), this, SLOT(onAccept()));

	connect(slRed, SIGNAL(valueChanged(int)), this, SLOT(onsliderMoved()));
	connect(slGreen, SIGNAL(valueChanged(int)), this, SLOT(onsliderMoved()));
	connect(slBlue, SIGNAL(valueChanged(int)), this, SLOT(onsliderMoved()));
	
	m_model = new CSchemasModel(m_data);
	tableView->setModel(m_model);
	tableView->setColumnHidden( 2, true ); 
	
	lblCor->setBackgroundRole(QPalette::Window);
	onsliderMoved();
}

CSchemas::~CSchemas()
{
	if (m_model)
	    delete m_model;
}

void CSchemas::onAccept()
{
	m_model->CommitData();
}

void CSchemas::onsliderMoved()
{
	QPalette palette;
	palette.setColor(QPalette::Window, QColor(slRed->value(),slGreen->value(),slBlue->value()));
	lblCor->setPalette(palette);
}

void CSchemas::on_pbAlterar_clicked()
{
	int icolor	= (slRed->value() * 65536) +
					(slGreen->value() * 256) +
					(slBlue->value());
	
	m_model->setData(m_activeIndex, icolor, Qt::BackgroundColorRole);
}

void CSchemas::on_tableView_pressed( const QModelIndex & index )
{
	if ( index.column() < 2 )
	{
		m_activeIndex = index;
		
		int iRed, iGreen, iBlue;
		QColor color = m_model->data(m_activeIndex, Qt::BackgroundColorRole).value<QColor>();
		
		color.getRgb(&iRed, &iGreen, &iBlue);
		
		slRed->setValue(iRed);
		slGreen->setValue(iGreen);
		slBlue->setValue(iBlue);
	}
}

void CSchemas::on_pbAdcionar_clicked()
{
	QModelIndex index = m_model->index( m_model->rowCount(), 0 );
	m_model->insertRows(m_model->rowCount(), 1, index);
}

void CSchemas::on_pbRemover_clicked()
{
	QModelIndex index = tableView->selectionModel()->currentIndex();
	
	if (index.isValid())
	{		
		int i = m_model->headerData( index.row(), Qt::Vertical ).toInt();
		
		if (! QMessageBox::question(
		    this,
		    tr("Excluir Esquema de Cores?"),
		    tr("Tem certeza que deseja excluir este esquema de cores <b>%1</b>?")
		    .arg(QString::number(i)),
		    tr("&Sim"), tr("&N�o"),
		    QString(), 1, 0))
		{
			m_model->removeRows(index.row(), 1);
		}
	}
}
