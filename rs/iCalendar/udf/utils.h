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
 
#ifndef __INCLUDE_UTILS_H
#define __INCLUDE_UTILS_H

#include "udf.h"

datetime IsctstoDateTime( const ISC_TIMESTAMP * ts );

char * stringToChar( string s );

string strReplace( string str, string frm, string to );

string intToString( int value, int digits = 0 );

string isoDate( const datetime dt );

string BlobToString( BLOBCALLBACK blob );

#endif //__INCLUDE_UTILS_H
