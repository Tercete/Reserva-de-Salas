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

#include "CAreas.h"
#include <QMessageBox>

CAreas::CAreas ( CData* _data, CMainWindow* _form ) :
		QDialog ( _form ),
		m_model ( 0 )
{
	setupUi ( this );
	setAttribute ( Qt::WA_DeleteOnClose );

	m_model = new CAreasModel ( _data );
	tableView->setModel ( m_model );

	connect ( this, SIGNAL ( accepted() ), this, SLOT ( onAccept() ) );
	connect ( this, SIGNAL ( accepted() ), _form, SLOT ( refreshAreas() ) );
}

CAreas::~CAreas()
{
	if ( m_model )
		delete m_model;
}

void CAreas::onAccept()
{
	m_model->CommitData();
}

void CAreas::on_pbAdcionar_pressed()
{
	m_model->insertRows ( m_model->rowCount(), 1 );
}

void CAreas::on_pbRemover_pressed()
{
	QModelIndex index = tableView->selectionModel()->currentIndex();

	if ( index.isValid() )
	{

		if ( ! QMessageBox::question (
		            this,
		            tr ( "Excluir �rea?" ),
		            tr ( "Tem certeza que deseja excluir a �rea %1?" )
		            .arg ( index.data().toString() ),
		            tr ( "&Sim" ), tr ( "&N�o" ),
		            QString(), 1, 0 ) )
		{
			m_model->removeRows ( index.row(), 1 );
		}
	}
}
