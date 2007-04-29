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

#include "CSalasItem.h"
#include "CSalas.h"

CSalasItem::CSalasItem ( PSala _sala, CSalas *_form ) :
		QDialog ( _form ),
		m_sala ( _sala ),
		m_validAndar ( 0, 4, this ),
		m_validSalaID ( 0, 999, this )
{
	setupUi ( this );
	setAttribute ( Qt::WA_DeleteOnClose );

	connect ( this, SIGNAL ( rejected() ), this, SLOT ( cancel() ) );

	connect ( okButton, SIGNAL ( clicked() ), this, SLOT ( ok() ) );
	connect ( this, SIGNAL ( accepted() ), _form, SLOT ( refreshData() ) );

	connect ( leNome, SIGNAL ( textChanged ( QString ) ), this, SLOT ( onValidate() ) );
	connect ( leSalaID, SIGNAL ( textChanged ( QString ) ), this, SLOT ( onValidate() ) );

	leAndar->setValidator ( &m_validAndar );
	leSalaID->setValidator ( &m_validSalaID );

	leAndar->setText ( QString::number ( m_sala->getAndar() ) );
	leNome->setText ( m_sala->getNome() );
	leSalaID->setText ( QString::number ( m_sala->getSalaID() ) );

	cbArea->addItems ( *_form->getData()->getAreas() );

	int i = cbArea->findText ( _sala->getArea() );
	if ( i != -1 )
		cbArea->setCurrentIndex ( i );

	onValidate();
}

CSalasItem::~CSalasItem()
{}

void CSalasItem::ok()
{
	m_sala->setAndar ( leAndar->text().toInt() );
	m_sala->setNome ( leNome->text() );
	m_sala->setSalaID ( leSalaID->text().toInt() );
	m_sala->setArea ( cbArea->currentText() );

	try
	{
		m_sala->save();
		emit accepted();
		close();
	}
	catch ( int SQLCode )
	{
		if ( SQLCode == -803 )
		{
			QMessageBox msg ( tr ( "Erro" ), tr ( "Esse n�mero de sala j� existe!" ), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 );
			msg.setWindowIcon ( QIcon ( ":/png/buttons/16/agt_update_critical.png" ) );
			msg.setIconPixmap ( QPixmap ( ":/png/buttons/16/kopete016.png" ) );
			msg.exec();
		}
	}
}

void CSalasItem::cancel()
{}

void CSalasItem::onValidate()
{
	okButton->setEnabled ( leNome->text().length() &&
	                       leSalaID->text().length() );
}
