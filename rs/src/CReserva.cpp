#include "CReserva.h"
#include "CReservaList.h"
#include "CReservaItem.h"
#include "CSala.h"
#include "main.h"
#include "CData.h"

static QPalette *g_disabledPalette = 0;

void exitFunction()
{
	if (g_disabledPalette)
	    delete g_disabledPalette;
}


CReserva::CReserva(CReservaList *_owner):
	QFrame(_owner, 0),
    m_owner(_owner),
	oldRESERVAID(-1),
	RESERVAID(0),
	SALAID(0),
	oldSALAID(0),
	HORAIN(QTime(0,0,0)),
	HORAFIM(QTime(0,0,0)),
	DATA(QDate(0,0,0)),
	USUARIOID(0),
	TIPO('S'),
	m_relocate(false),
	m_height(0),
	m_deleting(false),
	m_readSemanal(false),
	m_readMensal(false),
	m_parent(0)
{
	if (! g_disabledPalette)
	{
		g_disabledPalette = new QPalette();
		atexit(exitFunction);

		g_disabledPalette->setColor(QPalette::Base, QColor(200,200,200));
		g_disabledPalette->setColor(QPalette::Text, QColor(0,0,0));
	}
	
	resize(QSize(215, 56).expandedTo(minimumSizeHint()));
	QSizePolicy FormsizePolicy(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
	FormsizePolicy.setHorizontalStretch(0);
	FormsizePolicy.setVerticalStretch(0);
	FormsizePolicy.setHeightForWidth(false);
	setSizePolicy(FormsizePolicy);
		
	vboxLayout = new QVBoxLayout(this);
	vboxLayout->setSpacing(1);
	vboxLayout->setMargin(0);
	vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
	hboxLayout = new QHBoxLayout();
	hboxLayout->setSpacing(0);
	hboxLayout->setMargin(0);
	hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
	vboxLayout1 = new QVBoxLayout();
	vboxLayout1->setSpacing(0);
	vboxLayout1->setMargin(0);
	vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));

#if QT_VERSION < 0x040200
	QSizePolicy sizePolicyFixed(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(13));
#else
	QSizePolicy sizePolicyFixed(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(1));
#endif
	sizePolicyFixed.setHorizontalStretch(0);
	sizePolicyFixed.setVerticalStretch(0);
	sizePolicyFixed.setHeightForWidth(false);

	QFont font;
	#ifdef __unix__
	font.setPointSize(11);
	#else
	font.setFamily(QString::fromUtf8("Sans Serif"));
	font.setPointSize(9);
	#endif
	font.setBold(true);
	font.setItalic(false);
	font.setUnderline(false);
	font.setStrikeOut(false);

	lblHoraIn = new QLabel(this);
	lblHoraIn->setObjectName(QString::fromUtf8("lblHoraIn"));
	lblHoraIn->resize(QSize(140, 132));
	lblHoraIn->setSizePolicy(sizePolicyFixed);
	lblHoraIn->setMargin(0);
	lblHoraIn->setFont(font);
	lblHoraIn->setTextFormat(Qt::PlainText);
	lblHoraIn->setAlignment(Qt::AlignCenter);

	vboxLayout1->addWidget(lblHoraIn);
	
	lblHoraFim = new QLabel(this);
	lblHoraFim->setObjectName(QString::fromUtf8("lblHoraFim"));
	lblHoraFim->setTextFormat(Qt::PlainText);
	lblHoraFim->setScaledContents(false);
	lblHoraFim->setAlignment(Qt::AlignCenter);
	lblHoraFim->resize(QSize(140, 132));
	lblHoraFim->setSizePolicy(sizePolicyFixed);
	lblHoraFim->setMargin(0);
	lblHoraFim->setFont(font);
	
	vboxLayout1->addWidget(lblHoraFim);
	
	hboxLayout->addLayout(vboxLayout1);
	
	lblTitulo = new QLabel(this);
	lblTitulo->setObjectName(QString::fromUtf8("lblTitulo"));
	QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(13), static_cast<QSizePolicy::Policy>(13));
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(lblTitulo->sizePolicy().hasHeightForWidth());
	lblTitulo->setSizePolicy(sizePolicy);
	lblTitulo->setTextFormat(Qt::RichText);
	lblTitulo->setAlignment(Qt::AlignCenter);
	lblTitulo->setWordWrap(true);
	lblTitulo->setMargin(0);
	
	hboxLayout->addWidget(lblTitulo);
	
	vboxLayout->addLayout(hboxLayout);
	
	setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
	setLineWidth(2);
	setMidLineWidth(1);
}

CReserva::~CReserva()
{
	m_deleting = true;
	
	if (m_parent) 
	{
		m_parent->m_children.removeAll(this);
		if (! m_parent->m_deleting)
			delete m_parent;
	}
	else	
		if (m_children.count())
			while(m_children.count())
				delete m_children[m_children.count()-1];
	
	delete lblTitulo;
	delete lblHoraFim;
	delete lblHoraIn;
	delete vboxLayout1;
	delete hboxLayout;
	delete vboxLayout;
}

void CReserva::readSemanal()
{
	if (m_deleting)
		return;
		
	Database db = m_owner->m_owner->m_owner->m_db;
	
	try
	{
		Transaction tr = TransactionFactory(db, amWrite);
		tr->Start();
		
		Statement stmt = StatementFactory(db, tr);
		
		stmt->Prepare("Select \
							DATAIN, DATAFIM, SEG, TER, QUA, QUI, SEX, SAB, DOM, REVESA \
						From \
							RESERVA_SEMANAL \
						Where \
							RESERVAID = ?");
		stmt->Set(1, RESERVAID);
		stmt->Execute();
		
		stmt->Fetch();
		
		Date dt;
		int y, mo, d;
		
		stmt->Get(1, dt);
		dt.GetDate(y, mo, d);
		DATAIN = QDate(y, mo, d);
		
		stmt->Get(2, dt);
		dt.GetDate(y, mo, d);
		DATAFIM = QDate(y, mo, d);
		
		#define readDOWValues(INT) \
			if (stmt->IsNull(INT + 3)) \
				DIAS[INT] = false; \
			else \
			{ \
				stmt->Get(INT + 3, y); \
				DIAS[INT] = y; \
			} 
		
		readDOWValues(0);
		readDOWValues(1);
		readDOWValues(2);
		readDOWValues(3);
		readDOWValues(4);
		readDOWValues(5);
		readDOWValues(6);
		
		if (stmt->IsNull(10)) 
			REVESA = false; 
		else 
		{ 
				stmt->Get(10, y); 
				REVESA = y; 
		} 
		
		stmt->Close();
		
		m_readSemanal = true;
	}
	catch (Exception &e)
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox("Erro", e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0).exec();
		throw;
	}
}

void CReserva::readMensal()
{
	if (m_deleting)
		return;
		
	Database db = m_owner->m_owner->m_owner->m_db;
	
	try
	{
		Transaction tr = TransactionFactory(db, amWrite);
		tr->Start();
		
		Statement stmt = StatementFactory(db, tr);
		
		stmt->Prepare("Select \
							DATAFIM, DIA_S, ORDEM \
						From \
							RESERVA_MENSAL \
						Where \
							RESERVAID = ?");
		stmt->Set(1, RESERVAID);
		stmt->Execute();
		
		stmt->Fetch();
		
		Date dt;
		int y, mo, d;
		
		stmt->Get(1, dt);
		dt.GetDate(y, mo, d);
		DATAFIM = QDate(y, mo, d);
		
		stmt->Get(2, ORDEM);
		stmt->Get(3, DIA_S);
		
		stmt->Close();
		
		m_readSemanal = true;
	}
	catch (Exception &e)
	{
		std::cerr << e.ErrorMessage() << std::endl;
		QMessageBox("Erro", e.ErrorMessage(), QMessageBox::Warning, QMessageBox::Cancel, 0, 0).exec();
		throw;
	}
}

QDate CReserva::getDATAIN()
{
	if ((TIPO == 'W') && (!m_readSemanal))
		readSemanal();
	else
		if ((TIPO == 'M') && (!m_readMensal))
			readMensal();
	
	return DATAIN;
}

QDate CReserva::getDATAFIM()
{
	if ((TIPO == 'W') && (!m_readSemanal))
		readSemanal();
	else
		if ((TIPO == 'M') && (!m_readMensal))
			readMensal();
	
	return DATAFIM;
}

bool CReserva::getDOW(int _day)
{
	if ((_day < 0) || (_day > 6))
	{
		std::cerr << "Index out of bounds!" << std::endl;
		std::cerr << "getDOW(" << _day << ")" << std::endl;
		throw QString("Index out of bounds!");
	}
	
	if (!m_readSemanal)
		readSemanal();
	
	return DIAS[_day];
}

bool CReserva::getREVESA()
{
	if (!m_readSemanal)
		readSemanal();

	return REVESA;
}

void CReserva::setDOW(int _day, bool _value)
{
	if ((_day < 0) || (_day > 6))
	{
		std::cerr << "Index out of bounds!" << std::endl;
		std::cerr << "getDOW(" << _day << ")" << std::endl;
		throw QString("Index out of bounds!");
	}
	
	DIAS[_day] = _value;
}

bool CReserva::save()
{
	if (m_deleting)
		return false;
		
	Database db = m_owner->m_owner->m_owner->m_db;
	
	try
	{
		Transaction tr = TransactionFactory(db, amWrite);
		tr->Start();
		
		Statement stmt = StatementFactory(db, tr);

		if (oldRESERVAID == -1)
		{
			USUARIOID = CConfig::getConfig()->getUsuarioID();
			USUARIO = CConfig::getConfig()->getUserName();

			stmt->Execute("Select GEN_ID(GENRESERVAS, 1) From RDB$DATABASE");
			stmt->Fetch();
			stmt->Get(1, RESERVAID);
			stmt->Close();
			
			if (m_owner->m_owner->m_reservaItems[RESERVAID])
				m_owner->m_owner->m_reservaItems[RESERVAID]->addChild(this);
			else
				m_owner->m_owner->m_reservaItems.insert(RESERVAID, this);
			
			m_relocate = true;
		}

		switch (TIPO)
		{
			case 'S': // Simples
			{
				stmt->Prepare("Select OUT_RESERVAID, SEQ From CREATE_RESERVA_SIMPLES(?, ?, ?, ?, ?, ?, ?, ?, ?)");
		
				stmt->Set(1, oldRESERVAID);
				stmt->Set(2, SALAID);
				stmt->Set(3, USUARIOID);
				stmt->Set(4, ASSUNTO.toStdString());
				stmt->Set(5, DEPTO.toStdString());
				stmt->Set(6, NOTAS.toStdString());
				stmt->Set(7, Date(DATA.year(), DATA.month(), DATA.day()));
				stmt->Set(8, Time(HORAIN.hour(), HORAIN.minute(), HORAIN.second()));
				stmt->Set(9, Time(HORAFIM.hour(), HORAFIM.minute(), HORAFIM.second()));
				
				break;
			}
			case 'W': // Semanal
			{
				stmt->Prepare("Select OUT_RESERVAID, SEQ From CREATE_RESERVA_SEMANAL(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		
				stmt->Set(1, oldRESERVAID);
				stmt->Set(2, SALAID);
				stmt->Set(3, USUARIOID);
				stmt->Set(4, ASSUNTO.toStdString());
				stmt->Set(5, DEPTO.toStdString());
				stmt->Set(6, NOTAS.toStdString());
				stmt->Set(7, Date(DATA.year(), DATA.month(), DATA.day()));
				stmt->Set(8, Date(DATAFIM.year(), DATAFIM.month(), DATAFIM.day()));
				stmt->Set(9, Time(HORAIN.hour(), HORAIN.minute(), HORAIN.second()));
				stmt->Set(10, Time(HORAFIM.hour(), HORAFIM.minute(), HORAFIM.second()));

				for (int i = 0; i < 7; ++i)
					stmt->Set(i + 11, DIAS[i] ? 1 : 0);

				stmt->Set(18, (int)(REVESA));
				
				break;
			}
			case 'M': // Mensal
			{
				std::cerr << "Unknown TYPE:" << TIPO << std::endl;
				break;
			}
			default:
			{
				std::cerr << "Unknown TYPE:" << TIPO << std::endl;
				break;
			}
		}

		stmt->Execute();
		
		stmt->Fetch();
		stmt->Get(1, RESERVAID);
		stmt->Get(2, m_owner->m_owner->m_lastUpdate);
		
		stmt->Close();

		m_owner->m_owner->m_owner->m_notify->incIgnoreCount();

		tr->Commit();

		oldRESERVAID = RESERVAID;
		
		if (m_relocate)
		{
			relocate();
			if (m_deleting)
				return false;
		}

		refreshData();

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

void CReserva::relocate()
{
	QDate segunda = m_owner->m_owner->m_date;
	
	if ((DATA < segunda) || (DATA >= segunda.addDays(8)))
	{
		m_owner->m_reservas.removeAll(this);
		delete this;
		return;
	}
	else
	{
		if ((DATA.daysTo(m_owner->m_date)) || (oldSALAID != SALAID))
		{
			m_owner->m_reservas.removeAll(this);

			int idow = segunda.daysTo(DATA) + 1;

			CReservaList *reservaList = m_owner->m_owner->getReservaList(idow, SALAID);

			if (reservaList)
			{
				reservaList->insertReserva(this);
				m_owner = reservaList;
				
				oldSALAID = SALAID;
			}
			else
			{
				delete this;
				return;
			}
		}
	}
	
	m_relocate = false;
}

bool CReserva::del()
{
	Database db = m_owner->m_owner->m_owner->m_db;

	try
	{
		Transaction tr = TransactionFactory(db, amWrite);
		tr->Start();
	
		Statement stmt = StatementFactory(db, tr);
	
		if (oldRESERVAID != -1)
		{
			stmt->Prepare("delete from RESERVAS where RESERVAID = ?");

			stmt->Set(1, oldRESERVAID);
		}

		stmt->Execute();

		stmt->Execute("Select GEN_ID(SEQRESERVAS, 0) From RDB$DATABASE");
		stmt->Fetch();
		stmt->Get(1, m_owner->m_owner->m_lastUpdate);

		m_owner->m_owner->m_owner->m_notify->incIgnoreCount();
		tr->Commit();
	
		m_owner->m_reservas.removeAll(this);
	
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

void CReserva::refreshData()
{
	if (m_deleting)
		return;
	
	setToolTip("Resp.: " + USUARIO + '\n' + NOTAS);

	lblHoraIn->setText(HORAIN.toString("HH:mm"));
	lblHoraFim->setText(HORAFIM.toString("HH:mm"));

	QString s = ASSUNTO;
	
	if (DEPTO.length())
		s += "<br><i>(" + DEPTO + ")</i>";
	
	lblTitulo->setText(s);

	if ((m_colorScheme) &&
			(((DATA == QDate::currentDate()) && (HORAFIM >= QTime::currentTime())) ||
			(DATA > QDate::currentDate())))
		this->setPalette(*m_colorScheme);
	else
		this->setPalette(*g_disabledPalette);

	m_height = lblTitulo->heightForWidth(150) + 5;
}

void CReserva::mouseDoubleClickEvent(QMouseEvent * event)
{
	switch (CConfig::getConfig()->getNivel())
	{
		case 0: return;
		case 1:
			if (USUARIOID != CConfig::getConfig()->getUsuarioID())
				return;
		case 2:
			if ( CConfig::getConfig()->getUserSalaList()->indexOf(SALAID) == -1 )
				return;
	}

	CReservaItem *reservaItem = new CReservaItem(this, m_owner->m_owner->m_salas,
										m_owner->m_owner->m_parent);

	reservaItem->setSala(SALAID);
	
	if (TIPO == 'S')
		reservaItem->setDate(DATA);
	else
	{
		reservaItem->setDate(getDATAIN());
		reservaItem->setDateFim(getDATAFIM());
	}
	
	reservaItem->setModal(true);
	reservaItem->show();
}

void CReserva::mousePressEvent(QMouseEvent * event)
{
	CMainWindow* form = m_owner->m_owner->m_parent;
	form->setActiveReserva(this);
	
	if (event->button() == Qt::RightButton)
		m_owner->emit showReservaMenu(mapToGlobal(event->pos()));

	CSalaList* salaList = m_owner->m_owner->m_salas;
	PSala sala = salaList->m_salas[SALAID];
	
	form->tbReservas->setCurrentCell(DATA.dayOfWeek() - 1, sala->m_column);
}

void CReserva::paintEvent(QPaintEvent * event)
{
	{
		QPainter painter(this);
		
		if ((m_colorScheme) &&
				(((DATA == QDate::currentDate()) && (HORAFIM >= QTime::currentTime())) ||
				(DATA > QDate::currentDate())))
			painter.fillRect(event->rect(), m_colorScheme->color(QPalette::Base));
		else
			painter.fillRect(event->rect(), QColor(225,225,225));
	}
	
	QFrame::paintEvent(event);
}