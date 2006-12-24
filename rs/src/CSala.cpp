//
// C++ Implementation: CSala
//
// Description: 
//
//
// Author: Gianni Rossi <gianni.rossi@gmail.com>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
CSala::CSala(CSalaList *_owner):
    m_owner(_owner),
	SALAID(0),
	oldSALAID(-1),
	ANDAR(0)
{
}

CSala::~CSala()
{
}

void CSala::setSalaID(const int _salaID)
{
	if (SALAID)
		m_owner->m_salas.remove(SALAID);
		
	SALAID = _salaID;
	m_owner->m_salas.insert(SALAID, this);
}

bool CSala::save()
{
	Database db = m_owner->m_owner->m_db;
	
	try
	{
		Statement stmt = StatementFactory(db, *(m_owner->m_tr));

		if (oldSALAID == -1)
		{
			stmt->Prepare("insert into SALAS (SALAID, ANDAR, NOME) values (?, ?, ?)");

			stmt->Set(1, SALAID);
			stmt->Set(2, ANDAR);
			stmt->Set(3, NOME.toStdString());
			stmt->Execute();
			stmt->Close();
		}
		else
		{
			stmt->Prepare("update SALAS set SALAID = ?, ANDAR = ?, NOME = ? where SALAID = ?");

			stmt->Set(1, SALAID);
			stmt->Set(2, ANDAR);
			stmt->Set(3, NOME.toStdString());
			stmt->Set(4, oldSALAID);
			stmt->Execute();
			stmt->Close();

			stmt->Prepare("delete from SALAS_AREAS where SALAID = ?");
			stmt->Set(1, oldSALAID);
			stmt->Execute();
			stmt->Close();
		}

		
		stmt->Prepare("insert into SALAS_AREAS (SALAID, AREAID) \
						select \
							?, \
							AREAID \
						from \
							AREAS \
						where \
							AREA = ?");
		stmt->Set(1, SALAID);
		stmt->Set(2, AREA.toStdString());
		stmt->Execute();
		
		oldSALAID = SALAID;
		m_owner->m_salas.insert(SALAID, this);

		
		return true;
	}
	catch (SQLException &e)
	{
		std::cerr << e.ErrorMessage() << std::endl;
		throw e.SqlCode();
		return false;
	}
	catch (Exception &e)
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox("Erro", e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0).exec();
		return false;
	}
}

bool CSala::del()
{
	Database db = m_owner->m_owner->m_db;

	try
	{
		Statement stmt = StatementFactory(db, *(m_owner->m_tr));

		if (oldSALAID != -1)
		{
			stmt->Prepare("delete from SALAS where SALAID = ?");

			stmt->Set(1, oldSALAID);
		}

		stmt->Execute();
		(*m_owner->m_tr)->CommitRetain();

		m_owner->m_salas.remove(SALAID);

		delete this;
		return true;
	}
	catch (Exception &e)
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox("Erro", e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0).exec();
		return false;
	}
}