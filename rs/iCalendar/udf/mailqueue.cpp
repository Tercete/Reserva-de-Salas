/*
	Reserva de Salas
	Copyright 2007 Gianfranco Rossi.

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
#ifdef MT
 
#include "mailqueue.h"
#include "smtpsend.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <list>

static boost::thread			*mailQueue = 0;
static boost::mutex				mailMutex;
static boost::condition			waitCond;

typedef std::list<ICalMessage*>	ICalMessageList;
static ICalMessageList			mailList;

static bool						terminateQueue = false;

#define SCOPE_LOCK boost::mutex::scoped_lock __MUTEX_LOCKER(mailMutex)

void mailQueueLoop()
{
	waitCond.notify_one();
	
	while (!terminateQueue)
	{
		{
			SCOPE_LOCK;
			
			waitCond.wait(__MUTEX_LOCKER);
			
			ICalMessageList::const_iterator it;
			for(it = mailList.begin(); it != mailList.end(); ++it)
			{
				SMTPSend sender(&g_config);
				sender.send( *it );
				delete *it;
			}
			mailList.clear();
		}
	}
}

void enqueueMail( ICalMessage *message )
{
	SCOPE_LOCK;
	
	if ( !mailQueue )
	{
		mailQueue = new boost::thread(mailQueueLoop);
		waitCond.wait(__MUTEX_LOCKER);  // Wait for the thread to initialize
	}
	
	mailList.push_back( message );
	waitCond.notify_one();
}
#endif // MT
