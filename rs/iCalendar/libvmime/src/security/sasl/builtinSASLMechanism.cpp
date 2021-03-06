//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002-2006 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#include <gsasl.h>

#include "vmime/security/sasl/builtinSASLMechanism.hpp"

#include "vmime/security/sasl/SASLContext.hpp"
#include "vmime/security/sasl/SASLSession.hpp"

#include "vmime/exception.hpp"

#include <stdexcept>
#include <new>


namespace vmime {
namespace security {
namespace sasl {


builtinSASLMechanism::builtinSASLMechanism(ref <SASLContext> ctx, const string& name)
	: m_context(ctx), m_name(name), m_complete(false)
{
}


builtinSASLMechanism::~builtinSASLMechanism()
{
}


const string builtinSASLMechanism::getName() const
{
	return m_name;
}


const bool builtinSASLMechanism::step
	(ref <SASLSession> sess, const byte_t* challenge, const int challengeLen,
	 byte_t** response, int* responseLen)
{
	char* output = 0;
	size_t outputLen = 0;

	const int result = gsasl_step(sess->m_gsaslSession,
		reinterpret_cast <const char*>(challenge), challengeLen,
		&output, &outputLen);

	if (result == GSASL_OK || result == GSASL_NEEDS_MORE)
	{
		byte_t* res = new byte_t[outputLen];

		for (size_t i = 0 ; i < outputLen ; ++i)
			res[i] = output[i];

		*response = res;
		*responseLen = outputLen;

		free(output);
	}
	else
	{
		*response = 0;
		*responseLen = 0;
	}

	if (result == GSASL_OK)
	{
		// Authentication process completed
		m_complete = true;
		return true;
	}
	else if (result == GSASL_NEEDS_MORE)
	{
		// Continue authentication process
		return false;
	}
	else if (result == GSASL_MALLOC_ERROR)
	{
		throw std::bad_alloc();
	}
	else
	{
		throw exceptions::sasl_exception("Error when processing challenge: "
			+ SASLContext::getErrorMessage("gsasl_step", result));
	}
}


const bool builtinSASLMechanism::isComplete() const
{
	return m_complete;
}


void builtinSASLMechanism::encode
	(ref <SASLSession> sess, const byte_t* input, const int inputLen,
	 byte_t** output, int* outputLen)
{
	char* coutput = 0;
	size_t coutputLen = 0;

	if (gsasl_encode(sess->m_gsaslSession,
		reinterpret_cast <const char*>(input), inputLen,
		&coutput, &coutputLen) != GSASL_OK)
	{
		throw exceptions::sasl_exception("Encoding error.");
	}

	try
	{
		byte_t* res = new byte_t[coutputLen];

		std::copy(coutput, coutput + coutputLen, res);

		*output = res;
		*outputLen = static_cast <int>(coutputLen);
	}
	catch (...)
	{
		free(coutput);
		throw;
	}

	free(coutput);
}


void builtinSASLMechanism::decode
	(ref <SASLSession> sess, const byte_t* input, const int inputLen,
	 byte_t** output, int* outputLen)
{
	char* coutput = 0;
	size_t coutputLen = 0;

	try
	{
		if (gsasl_decode(sess->m_gsaslSession,
			reinterpret_cast <const char*>(input), inputLen,
			&coutput, &coutputLen) != GSASL_OK)
		{
			throw exceptions::sasl_exception("Decoding error.");
		}

		byte_t* res = new byte_t[coutputLen];

		std::copy(coutput, coutput + coutputLen, res);

		*output = res;
		*outputLen = static_cast <int>(coutputLen);
	}
	catch (...)
	{
		free(coutput);
		throw;
	}

	free(coutput);
}


} // sasl
} // security
} // vmime

