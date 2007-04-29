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
#ifndef CUSUARIOSAREAS_H_
#define CUSUARIOSAREAS_H_

#include <QWidget>
#include <QDialog>
#include <QStringList>
#include "../obj/ui_frusersareas.h"
#include "CData.h"

class CUsuariosAreas: public QDialog, public Ui::frUsersAreas
{
		Q_OBJECT

	public:
		CUsuariosAreas ( CData * _data, QWidget * _parent = 0 );
		virtual ~CUsuariosAreas();

	private:
		QStringList		m_areas;

	public:
		void setUserAreas ( QString _areas );
		QString getUserAreas();

	public slots:
		void on_tbAdd_clicked();
		void on_tbAddAll_clicked();
		void on_tbRemove_clicked();
		void on_tbRemoveAll_clicked();

		void on_lsAreas_doubleClicked ( const QModelIndex & index );
		void on_lsUserAreas_doubleClicked ( const QModelIndex & index );
};

#endif /*CUSUARIOSAREAS_H_*/
