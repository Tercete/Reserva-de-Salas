/*
	Reserva de Salas
	Copyright 2007 Gianfranco Rossi.

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
 
#ifndef MAILQUEUE_H
#define MAILQUEUE_H

#ifdef MT

#include "udf.h"
#include "icalmessage.h"
#include "smtpconfig.h"

void enqueueMail( ICalMessage *message );

#endif // MT

#endif
