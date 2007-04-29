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

#include "CAreasModel.h"
#include "main.h"

CAreasModel::CAreasModel ( CData* _data ) :
		QAbstractTableModel ( _data ),
		m_data ( _data )
{
	m_tr    = new Transaction();
	( *m_tr ) = TransactionFactory ( _data->m_db, amWrite, ilConcurrency, lrWait );
	( *m_tr )->Start();

	Statement stmt = StatementFactory ( _data->m_db, *m_tr );

	stmt->Execute ( "Select AREAID, AREA From AREAS Order By AREA" );

	std::string     s;
	ROW_AREAS		*row;

	while ( stmt->Fetch() )
	{
		row = new ROW_AREAS;
		m_rows.push_back ( row );

		stmt->Get ( 1, row->AREAID );

		stmt->Get ( 2, s );
		row->AREA = s.c_str();
	}
	stmt->Close();
}

CAreasModel::~CAreasModel()
{
	if ( ( *m_tr )->Started() )
		( *m_tr )->Rollback();

	TROW_AREAS::iterator it;
	for ( it = m_rows.begin(); it != m_rows.end(); ++it )
		delete *it;
}

int CAreasModel::rowCount ( const QModelIndex &parent ) const
{
	return m_rows.size();
}

int CAreasModel::columnCount ( const QModelIndex &parent ) const
{
	return 1;
}

QVariant CAreasModel::data ( const QModelIndex &index, int role ) const
{
	switch ( role )
	{
		case Qt::DisplayRole:
		case Qt::EditRole:
			{
				if ( index.row() >= 0 && index.row() < m_rows.size() &&
				        index.column() >= 0 && index.column() < 2 )
				{
					ROW_AREAS *row = m_rows[index.row() ];

					switch ( index.column() )
					{
						case 0: return row->AREA;
					}
				}
				return QVariant();
			}
	}
	return QVariant();
}

QVariant CAreasModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
	if ( role == Qt::DisplayRole )
	{
		if ( orientation == Qt::Horizontal )
		{
			switch ( section )
			{
				case 0: return tr ( "�rea" );
			}
			return QVariant();
		}
		else
		{
			if ( section < m_rows.size() )
				return m_rows[section]->AREAID;

			return QVariant();
		}
	}
	return QVariant();
}

bool CAreasModel::setData ( const QModelIndex &index, const QVariant &value, int role )
{
	if ( role == Qt::DisplayRole || role == Qt::EditRole )
	{
		ROW_AREAS *row = m_rows[index.row() ];

		try
		{
			Statement stmt = StatementFactory ( m_data->m_db, *m_tr );

			stmt->Prepare ( "Update AREAS Set AREA = ? Where AREAID = ?" );

			stmt->Set ( 1, value.toString().toStdString() );
			stmt->Set ( 2, row->AREAID );

			stmt->Execute();
			stmt->Close();

			row->AREA = value.toString();

			return true;
		}
		catch ( SQLException &e )
		{
			std::cerr << e.ErrorMessage() << std::endl;
			if ( e.SqlCode() == -803 )
				QMessageBox ( tr ( "Erro" ), tr ( "J� existe uma �rea com esse nome." ), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
			else
				QMessageBox ( tr ( "Erro" ), e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();

			return false;
		}
		catch ( Exception &e )
		{
			std::cerr << e.ErrorMessage() << std::endl;
			QMessageBox ( tr ( "Erro" ), e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
			return false;
		}
	}

	return false;
}

Qt::ItemFlags CAreasModel::flags ( const QModelIndex & index ) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool CAreasModel::insertRows ( int row, int count, const QModelIndex & parent )
{
	beginInsertRows ( parent, row, row + count - 1 );

	ROW_AREAS *rowData = new ROW_AREAS;
	try
	{
		Statement stmt = StatementFactory ( m_data->m_db, *m_tr );

		stmt->Execute ( "Select GEN_ID(GENAREAS, 1) From RDB$DATABASE" );

		stmt->Fetch();
		stmt->Get ( 1, rowData->AREAID );

		stmt->Close();

		rowData->AREA = tr ( "Nova �rea " ) + QString::number ( rowData->AREAID );

		m_rows.push_back ( rowData );


		stmt->Prepare ( "Insert into AREAS (AREAID, AREA) Values (?, ?)" );
		stmt->Set ( 1, rowData->AREAID );
		stmt->Set ( 2, rowData->AREA.toStdString() );
		stmt->Execute();

		endInsertRows();

		return true;
	}
	catch ( Exception &e )
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox ( tr ( "Erro" ), e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
	}
	return false;
}

bool CAreasModel::removeRows ( int row, int count, const QModelIndex & parent )
{
	beginRemoveRows ( parent, row, row + count - 1 );

	ROW_AREAS *rowData = m_rows[row];
	try
	{
		Statement stmt = StatementFactory ( m_data->m_db, *m_tr );

		stmt->Prepare ( "Delete From AREAS Where AREAID = ?" );
		stmt->Set ( 1, rowData->AREAID );
		stmt->Execute();
		stmt->Close();

		m_rows.removeAt ( row );

		endRemoveRows();

		return true;
	}
	catch ( Exception &e )
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox ( tr ( "Erro" ), e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0 ).exec();
	}
	return false;
}
