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

/* 
   Example from http://tools.ietf.org/html/rfc2447

   From: sman@netscape.com
   To: stevesil@microsoft.com
   Subject: Phone Conference
   Mime-Version: 1.0
   Content-Type:text/calendar; method=REQUEST; charset=US-ASCII
   Content-Transfer-Encoding: 7bit

   BEGIN:VCALENDAR
   PRODID:-//ACME/DesktopCalendar//EN
   METHOD:REQUEST
   VERSION:2.0
   BEGIN:VEVENT
   ORGANIZER:mailto:sman@netscape.com
   ATTENDEE;ROLE=CHAIR;ATTSTAT=ACCEPTED:mailto:sman@netscape.com
   ATTENDEE;RSVP=YES:mailto:stevesil@microsoft.com
   DTSTAMP:19970611T190000Z
   DTSTART:19970701T210000Z
   DTEND:19970701T230000Z
   SUMMARY:Phone Conference
   DESCRIPTION:Please review the attached document.
   UID:calsvr.example.com-873970198738777
   ATTACH:ftp://ftp.bar.com/pub/docs/foo.doc
   STATUS:CONFIRMED
   END:VEVENT
   END:VCALENDAR
*/

#include "udf.h"
#include "smtpconfig.h"
#include "smtpsend.h"
#include "icalmessage.h"

#ifdef MT
#include "mailqueue.h"
#endif

SMTPConfig	g_config;
std::string	g_from;

extern "C" 
{

extern int set_smtp_host( char * value )
{
	g_config.setHost( value );
	return 1;
}

extern int set_smtp_from( char * value )
{
	g_from = value;
	return 1;
}

extern int set_smtp_auth( int * value )
{
	(void)value;
	return 0;
}

extern int set_smtp_tls( int * value )
{
	(void)value;
	return 0;
}

extern int set_smtp_user_name( char * value )
{
	g_config.setUserName( value );
	return 1;
}

extern int set_smtp_password( char * value )
{
	g_config.setPassword( value );
	return 1;
}
	
extern int icalendar( char * uid, char * to, char * subject, BLOBCALLBACK description, char * location, ISC_TIMESTAMP * tsStart, ISC_TIMESTAMP * tsEnd, int * opr )
{
	SMTPSend	sender(&g_config);
	ICalMessage	message;
	
	std::string messageBody = BlobToString(description);
	
	message.setRecipient( to );
	message.setSubject( subject );
	message.setUid( uid );
	message.setStartTime( IsctstoDateTime(tsStart) );
	message.setEndTime( IsctstoDateTime(tsEnd) );
	message.setLocation( location );
	message.setOperation( static_cast<ICalMessage::Operations>(*opr) );
	message.setMessageBody(	messageBody );
	message.setSender( g_from );
	
	sender.send( message );
	return 0;
}

} // extern "C"
