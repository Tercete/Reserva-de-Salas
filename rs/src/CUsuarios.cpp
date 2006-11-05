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

CUsuarios::CUsuarios(CData* _data):
	m_data(_data),
	m_model(0),
	m_delegate(0)
{
	setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	
	connect(this, SIGNAL(accepted()), this, SLOT(onAccept()));
		
	m_model = new CUsuariosModel(m_data);
	tableView->setModel(m_model);

	m_delegate = new CComboBoxDelegate(this);
	tableView->setItemDelegate(m_delegate);
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
