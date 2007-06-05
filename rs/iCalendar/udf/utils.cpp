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
 
#include "utils.h"


datetime IsctstoDateTime( const ISC_TIMESTAMP * ts )
{
	STATIC_MT tm time;
	isc_decode_timestamp( ts, &time );
	
	return encodedate( time.tm_year + 1900, time.tm_mon + 1, time.tm_mday )
			+ encodetime( time.tm_hour, time.tm_min, time.tm_sec );
}

char * stringToChar( string s )
{
	STATIC_MT char *result, *p;
	STATIC_MT const char *q;

#ifdef MT
	result = static_cast<char*>( ib_util_malloc( length( s ) ));
#else
	static const int MAX_LENGTH = 255;
	static char buffer[ MAX_LENGTH + 1 ];
	result = buffer;
	
	if ( length( s ) > MAX_LENGTH )
		setlength( s, MAX_LENGTH );
#endif
	
	p = result;
	q = s;
	
	while ( *q )
		*p++ = *q++;

	// Copy the terminating 0
	*p = *q;
	
	return result;
}

string strReplace( string str, string frm, string to )
{
	return str;
}

string intToString( int value, int digits )
{
	static const int len = 48;
	STATIC_MT char buffer[len];
	STATIC_MT char * p;
	
	p = buffer + len - 1;
	*p-- = 0;
	
	if ( digits > ( len - 1))
		digits = len - 1;
	
	if ( value )
	{
		while ( value && ( p != buffer ))
		{
			*p-- = '0' + ( value - (( value / 10 ) * 10));
			value /= 10;
			digits--;
		}
	}
	else
	{
		*p-- = '0';
		digits--;
	}
	
	while (( --digits >= 0 ) && ( p != buffer ))
		*p-- = '0';
	
	string result = ++p;
	
	return result;
}

string isoDate( const datetime dt )
{
	STATIC_MT int year, month, day, hours, mins, secs, msecs;
	
	decodedate( dt, year, month, day );
	decodetime( dt, hours, mins, secs, msecs );

	string result;
	
	result = intToString( year, 4 ) + intToString( month, 2 ) + intToString( day, 2 )
			+ 'T' + intToString( hours, 2 ) + intToString( mins, 2 ) + intToString( secs, 2 );
	
	return result;
}

string BlobToString( BLOBCALLBACK blob )
{
	STATIC_MT string result;
#ifndef MT
	clear( result );
#endif
	
	if ( blob && blob->blob_handle )
	{
		int len = blob->blob_max_segment + 1L;
		ISC_UCHAR * buffer = static_cast<ISC_UCHAR*>( malloc( len ) );
		
		ISC_USHORT readLength = 0;

		while ( (*blob->blob_get_segment) ( blob->blob_handle, buffer, len, &readLength ) )
		{
			buffer[ readLength ] = 0;
			
			// I know, the double cast looks ugly; but it works!
			result += static_cast<char*>( static_cast<void*>( buffer ));
		}

		delete buffer;
	}

	return result;
}
