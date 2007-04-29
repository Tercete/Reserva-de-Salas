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
#include "CSala.h"
#include "main.h"
#include <QObject>

CSala::CSala ( CSalaList *_owner ) :
		m_owner ( _owner ),
		SALAID ( 0 ),
		oldSALAID ( -1 ),
		ANDAR ( 0 )
{}

CSala::~CSala()
{}

void CSala::setSalaID ( const int _salaID )
{
	if ( SALAID )
		m_owner->m_salas.remove ( SALAID );

	SALAID = _salaID;
	m_owner->m_salas.insert ( SALAID, this );
}

bool CSala::save()
{
	Database db = m_owner->m_owner->m_db;

	try
	{
		Statement stmt = StatementFactory ( db, * ( m_owner->m_tr ) );

		if ( oldSALAID == -1 )
		{
			stmt->Prepare ( "Insert into SALAS (SALAID, ANDAR, NOME) Values (?, ?, ?)" );

			stmt->Set ( 1, SALAID );
			stmt->Set ( 2, ANDAR );
			stmt->Set ( 3, NOME.toStdString() );
			stmt->Execute();
			stmt->Close();
		}
		else
		{
			stmt->Prepare ( "Update SALAS Set SALAID = ?, ANDAR = ?, NOME = ? Where SALAID = ?" );

			stmt->Set ( 1, SALAID );
			stmt->Set ( 2, ANDAR );
			stmt->Set ( 3, NOME.toStdString() );
			stmt->Set ( 4, oldSALAID );
			stmt->Execute();
			stmt->Close();

			stmt->Prepare ( "Delete From SALAS_AREAS Where SALAID = ?" );
			stmt->Set ( 1, oldSALAID );
			stmt->Execute();
			stmt->Close();
		}


		stmt->Prepare ( "Insert into SALAS_AREAS (SALAID, AREAID) \
							Select \
								?, \
								AREAID \
							From \
								AREAS \
							Where \
								AREA = ?" );
		stmt->Set ( 1, SALAID );
		stmt->Set ( 2, AREA.toStdString() );
		stmt->Execute();

		oldSALAID = SALAID;
		m_owner->m_salas.insert ( SALAID, this );


		return true;
	}
	catch ( SQLException &e )
	{
		std::cerr << e.ErrorMessage() << std::endl;
		throw e.SqlCode();
		return false;
	}
	catch ( Exception &e )
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox ( QObject::tr ( "Erro" ), e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
		return false;
	}
}

bool CSala::del()
{
	Database db = m_owner->m_owner->m_db;

	try
	{
		Statement stmt = StatementFactory ( db, * ( m_owner->m_tr ) );

		if ( oldSALAID != -1 )
		{
			stmt->Prepare ( "Delete From SALAS Where SALAID = ?" );

			stmt->Set ( 1, oldSALAID );
		}

		stmt->Execute();
		( *m_owner->m_tr )->CommitRetain();

		m_owner->m_salas.remove ( SALAID );

		delete this;
		return true;
	}
	catch ( Exception &e )
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox ( QObject::tr ( "Erro" ), e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
		return false;
	}
}
