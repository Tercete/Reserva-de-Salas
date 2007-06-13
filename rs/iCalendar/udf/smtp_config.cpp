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
 
#include "smtp_config.h"

static SMTP_Config * smtpConfig = 0;

int set_smtp_host( char * value )
{
	SMTP_Config::config()->setHost( value );
	return 1;
}

int set_smtp_from( char * value )
{
	SMTP_Config::config()->setFrom( value );
	return 1;
}

int set_smtp_auth( int * value )
{
	SMTP_Config::config()->setAuth( *value != 0 );
	return 1;
}

int set_smtp_tls( int * value )
{
	SMTP_Config::config()->setTls( *value != 0 );
	return 1;
}

int set_smtp_user_name( char * value )
{
	SMTP_Config::config()->setUserName( value );
	return 1;
}

int set_smtp_password( char * value )
{
	SMTP_Config::config()->setPassword( value );
	return 1;
}

SMTP_Config * SMTP_Config::config()
{
	if ( ! smtpConfig )
		smtpConfig = new SMTP_Config();
	
	return smtpConfig;
}

SMTP_Config::SMTP_Config():
		m_port( 25 )
{
}

SMTP_Config::~SMTP_Config()
{
}
