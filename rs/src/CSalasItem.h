/*
	Reserva de Salas
	Copyright 2006 Gianfranco Rossi.

	Este programa é software livre; você pode redistribuí-lo e/ou
	modificá-lo sob os termos da Licença Pública Geral GNU, conforme
	publicada pela Free Software Foundation; tanto a versão 2 da
	Licença.

	Este programa é distribuído na expectativa de ser útil, mas SEM
	QUALQUER GARANTIA; sem mesmo a garantia implícita de
	COMERCIALIZAÇÃO ou de ADEQUAÇÃO A QUALQUER PROPÓSITO EM
	PARTICULAR. Consulte a Licença Pública Geral GNU para obter mais
	detalhes.

	Você deve ter recebido uma cópia da Licença Pública Geral GNU
	junto com este programa; se não, escreva para a Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
	02111-1307, USA.
 */

#ifndef __INCLUDE_CSALASITEM_H
#define __INCLUDE_CSALASITEM_H

#include "main.h"
#include "../obj/ui_frsalasitem.h"
#include "CData.h"
#include "CSala.h"

#include <QIntValidator>

class CSalasItem: public QDialog, public Ui::SalasItem
{
		Q_OBJECT

	public:
		CSalasItem ( PSala _sala, CSalas *_form );
		~CSalasItem();

	private:
		PSala m_sala;

		QIntValidator m_validAndar;
		QIntValidator m_validSalaID;

	private slots:
		void ok();
		void cancel();

	public slots:
		void onValidate();
};

#endif //__INCLUDE_CSALASITEM_H
