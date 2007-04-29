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

#ifndef CDBSETTINGS_H_
#define CDBSETTINGS_H_

#include <QDialog>
#include "../obj/ui_frdbsettings.h"
#include "CMainWindow.h"

class CDBSettings: public QDialog, public Ui::frdbsettings
{
		Q_OBJECT

	public:
		CDBSettings ( CMainWindow *_mainWindow );
		virtual ~CDBSettings();

	private:
		CMainWindow		*m_mainWindow;
		int				m_result;

	public slots:
		void onClose();
		void onCancel();
		void on_helpButton_pressed();
};

#endif /*CDBSETTINGS_H_*/
