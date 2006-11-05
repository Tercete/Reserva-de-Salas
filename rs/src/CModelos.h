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

#ifndef __INCLUDE_CMODELOS_H
#define __INCLUDE_CMODELOS_H

#include "CData.h"
#include "../obj/ui_frmodelos.h"

#include <QTextDocument>
#include <QPrinter>

class CModelos: public QDialog, public Ui::Modelos
{
	Q_OBJECT

			friend class CModelosItem;
	
	public:
		CModelos(Database _db, CReservaList *_lista, const QString _sala, QPrinter *_printer);
		CModelos(Database _db, CReservaList::CReserva *_reserva, const QString _sala, QPrinter *_printer);
		~CModelos();

	private:
		struct ROW_MODELOS
		{
			int MODELOID;
			QString NOME;
			QString BODY;
			QString ITEM;
			QString FUNDO;
			QString FUNDOALT;
		};

		typedef QList<ROW_MODELOS*>	TModelosList;
		TModelosList m_modelos;

		Database	m_db;
		CReservaList	*m_lista;
		CReservaList::CReserva	*m_reserva;
		QString		m_sala;
		QPrinter	*m_printer;
		QString		m_doc;

		inline void init();
	public:
		int	getCount() const {return m_modelos.size();};
		QString getNomeModelo(const int _id) const {return m_modelos[_id]->NOME;};

	public slots:
		void render(const int _id);
		void onAccept();
		void onClose();

		void on_btAdd_clicked();
		void on_btEdit_clicked();
		void on_btDelete_clicked();
};

#endif // __INCLUDE_CMODELOS_H
