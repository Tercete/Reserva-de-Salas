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

#ifndef __INCLUDE_MAINWINDOW_H
#define __INCLUDE_MAINWINDOW_H

#include "main.h"
#include "../obj/ui_frmain.h"
#include "CData.h"
#include "CConfig.h"
#include "CSemana.h"
#include "CReservaList.h"

#include <QPrinter>
#include <QResizeEvent>

class CMainWindow: public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
	
	public:
		CMainWindow( QWidget * _parent = 0 );
		~CMainWindow();
	private:
		QActionGroup	m_stylesgroup;

		CSemana			*m_semana;
		CSalaList		*m_salaList;
		CReserva		*m_activeReserva;

		CData		m_data;
		QDate		m_date;
		CConfig		*m_config;
		
		QDate		m_activeDate;
		int			m_activeSalaID;
		
		void clearData();
		void updateButtons();

		QMenu		m_mnPopupReserva;
		QMenu		m_mnPopupHoje;
		QPrinter	m_printer;
		
		bool		m_needRefresh;
		bool		m_canRefresh;
		bool		m_initialized;
		
	private slots:
		void on_actionSalas_triggered();
 		void on_actionUsuarios_triggered();
 		void on_actionCores_triggered();
 		void on_actionAreas_triggered();
		void on_actionAdicionar_triggered();
		void on_actionRemover_triggered();
		void on_actionAlterar_triggered();
		void on_actionImprimirLista_triggered();
		void on_actionImprimirReserva_triggered();
		void on_actionCopiar_triggered();
		void on_actionHoje_triggered();
		void on_btAnte_clicked();
		void on_btProx_clicked();
		void onSetStyle();
		void cbAreaChanged(int index);
		
	protected:
		virtual void resizeEvent(QResizeEvent * event);
		virtual void showEvent ( QShowEvent * event );
		virtual void mousePressEvent ( QMouseEvent * event );
		
	public:
		void checkRowHeight(int _row, int _salaID);
		QDate getDate() {return m_date;}
		
		void setCanRefresh(bool _value) { m_canRefresh = _value; };
		void checkRefresh() {if (m_needRefresh) refreshData(m_date);};
		
		bool initialize();
		
	public slots:
		void refreshSalas();
		void refreshAreas();
		void refreshData(const QDate &_date);
		
		void setActiveReserva(CReserva *_reserva);
		void setActiveDate(QDate _date) {m_activeDate = _date;};
		void setActiveSalaID(int _salaID) {m_activeSalaID = _salaID;};

		void on_actionSobreRS_triggered();
		void on_actionSobreQt_triggered();

        void showReservaMenu(const QPoint _pos);
};

#endif // __INCLUDE_MAINWINDOW_H
