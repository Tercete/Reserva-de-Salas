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

#include "vmime/parameter.hpp"
#include "vmime/parserHelpers.hpp"

#include "vmime/text.hpp"


namespace vmime
{


parameter::parameter(const string& name)
	: m_name(name)
{
}


parameter::parameter(const string& name, const word& value)
	: m_name(name), m_value(value)
{
}


parameter::parameter(const string& name, const string& value)
	: m_name(name), m_value(value)
{
}


parameter::parameter(const parameter&)
	: component()
{
}


ref <component> parameter::clone() const
{
	ref <parameter> p = vmime::create <parameter>(m_name);
	p->copyFrom(*this);

	return (p);
}


void parameter::copyFrom(const component& other)
{
	const parameter& param = dynamic_cast <const parameter&>(other);

	m_name = param.m_name;
	m_value.copyFrom(param.m_value);
}


parameter& parameter::operator=(const parameter& other)
{
	copyFrom(other);
	return (*this);
}


const string& parameter::getName() const
{
	return m_name;
}


const word& parameter::getValue() const
{
	return m_value;
}


void parameter::setValue(const component& value)
{
	std::ostringstream oss;
	utility::outputStreamAdapter vos(oss);

	value.generate(vos);

	setValue(word(oss.str(), vmime::charsets::US_ASCII));
}


void parameter::setValue(const word& value)
{
	m_value = value;
}


void parameter::parse(const string& buffer, const string::size_type position,
	const string::size_type end, string::size_type* newPosition)
{
	m_value.setBuffer(string(buffer.begin() + position, buffer.begin() + end));
	m_value.setCharset(charset(charsets::US_ASCII));

	if (newPosition)
		*newPosition = end;
}


void parameter::parse(const std::vector <valueChunk>& chunks)
{
	bool foundCharsetChunk = false;

	charset ch(charsets::US_ASCII);

	std::ostringstream value;
	value.imbue(std::locale::classic());

	for (std::vector <valueChunk>::size_type i = 0 ; i < chunks.size() ; ++i)
	{
		const valueChunk& chunk = chunks[i];

		// Decode following data
		if (chunk.encoded)
		{
			const string::size_type len = chunk.data.length();
			string::size_type pos = 0;

			// If this is the first encoded chunk, extract charset
			// and language information
			if (!foundCharsetChunk)
			{
				// Eg. "us-ascii'en'This%20is%20even%20more%20"
				string::size_type q = chunk.data.find_first_of('\'');

				if (q != string::npos)
				{
					const string chs = chunk.data.substr(0, q);

					if (!chs.empty())
						ch = charset(chs);

					++q;
					pos = q;
				}

				q = chunk.data.find_first_of('\'', pos);

				if (q != string::npos)
				{
					// Ignore language
					++q;
					pos = q;
				}

				foundCharsetChunk = true;
			}

			for (string::size_type i = pos ; i < len ; ++i)
			{
				const string::value_type c = chunk.data[i];

				if (c == '%' && i + 2 < len)
				{
					string::value_type v = 0;

					// First char
					switch (chunk.data[i + 1])
					{
					case 'a': case 'A': v += 10; break;
					case 'b': case 'B': v += 11; break;
					case 'c': case 'C': v += 12; break;
					case 'd': case 'D': v += 13; break;
					case 'e': case 'E': v += 14; break;
					case 'f': case 'F': v += 15; break;
					default: // assume 0-9

						v += (chunk.data[i + 1] - '0');
						break;
					}

					v *= 16;

					// Second char
					switch (chunk.data[i + 2])
					{
					case 'a': case 'A': v += 10; break;
					case 'b': case 'B': v += 11; break;
					case 'c': case 'C': v += 12; break;
					case 'd': case 'D': v += 13; break;
					case 'e': case 'E': v += 14; break;
					case 'f': case 'F': v += 15; break;
					default: // assume 0-9

						v += (chunk.data[i + 2] - '0');
						break;
					}

					value << v;

					i += 2; // skip next 2 chars
				}
				else
				{
					value << c;
				}
			}
		}
		// Simply copy data, as it is not encoded
		else
		{
			// This syntax is non-standard (expressly prohibited
			// by RFC-2047), but is used by Mozilla:
			//
    			// Content-Type: image/png;
			//    name="=?us-ascii?Q?Logo_VMime=2Epng?="

			// Using 'vmime::text' to parse the data is safe even
			// if the data is not encoded, because it can recover
			// from parsing errors.
			vmime::text t;
			t.parse(chunk.data);

			if (t.getWordCount() != 0)
			{
				value << t.getWholeBuffer();

				if (!foundCharsetChunk)
					ch = t.getWordAt(0)->getCharset();
			}
		}
	}

	m_value.setBuffer(value.str());
	m_value.setCharset(ch);
}


void parameter::generate(utility::outputStream& os, const string::size_type maxLineLength,
	const string::size_type curLinePos, string::size_type* newLinePos) const
{
	const string& name = m_name;
	const string& value = m_value.getBuffer();

	// For compatibility with implementations that do not understand RFC-2231,
	// also generate a normal "7bit/us-ascii" parameter
	string::size_type pos = curLinePos;

	if (pos + name.length() + 10 + value.length() > maxLineLength)
	{
		os << NEW_LINE_SEQUENCE;
		pos = NEW_LINE_SEQUENCE_LENGTH;
	}

	bool needQuoting = false;
	string::size_type valueLength = 0;

	for (string::size_type i = 0 ; (i < value.length()) && (pos + valueLength < maxLineLength - 4) ; ++i, ++valueLength)
	{
		switch (value[i])
		{
		// Characters that need to be quoted _and_ escaped
		case '"':
		case '\\':
		// Other characters that need quoting
		case ' ':
		case '\t':
		case '(':
		case ')':
		case '<':
		case '>':
		case '@':
		case ',':
		case ';':
		case ':':
		case '/':
		case '[':
		case ']':
		case '?':
		case '=':

			needQuoting = true;
			break;
		}
	}

	const bool cutValue = (valueLength != value.length());  // has the value been cut?

	if (needQuoting)
	{
		os << name << "=\"";
		pos += name.length() + 2;
	}
	else
	{
		os << name << "=";
		pos += name.length() + 1;
	}

	bool extended = false;

	for (string::size_type i = 0 ; (i < value.length()) && (pos < maxLineLength - 4) ; ++i)
	{
		const char_t c = value[i];

		if (/* needQuoting && */ (c == '"' || c == '\\'))  // 'needQuoting' is implicit
		{
			os << '\\' << value[i];  // escape 'x' with '\x'
			pos += 2;
		}
		else if (parserHelpers::isAscii(c))
		{
			os << value[i];
			++pos;
		}
		else
		{
			extended = true;
		}
	}

	if (needQuoting)
	{
		os << '"';
		++pos;
	}

	// Also generate an extended parameter if the value contains 8-bit characters
	// or is too long for a single line
	if (extended || cutValue)
	{
		os << ';';
		++pos;

		/* RFC-2231
		 * ========
		 *
		 * Content-Type: message/external-body; access-type=URL;
		 *    URL*0="ftp://";
		 *    URL*1="cs.utk.edu/pub/moore/bulk-mailer/bulk-mailer.tar"
		 *
		 * Content-Type: application/x-stuff;
		 *    title*=us-ascii'en-us'This%20is%20%2A%2A%2Afun%2A%2A%2A
		 *
		 * Content-Type: application/x-stuff;
		 *    title*0*=us-ascii'en'This%20is%20even%20more%20
		 *    title*1*=%2A%2A%2Afun%2A%2A%2A%20
		 *    title*2="isn't it!"
		 */

		// Check whether there is enough space for the first section:
		// parameter name, section identifier, charset and separators
		// + at least 5 characters for the value
		const string::size_type firstSectionLength =
			  name.length() + 4 /* *0*= */ + 2 /* '' */
			+ m_value.getCharset().getName().length();

		if (pos + firstSectionLength + 5 >= maxLineLength)
		{
			os << NEW_LINE_SEQUENCE;
			pos = NEW_LINE_SEQUENCE_LENGTH;
		}

		// Split text into multiple sections that fit on one line
		int sectionCount = 0;
		std::vector <string> sectionText;

		string currentSection;
		string::size_type currentSectionLength = firstSectionLength;

		for (string::size_type i = 0 ; i < value.length() ; ++i)
		{
			// Check whether we should start a new line (taking into
			// account the next character will be encoded = worst case)
			if (currentSectionLength + 3 >= maxLineLength)
			{
				sectionText.push_back(currentSection);
				sectionCount++;

				currentSection.clear();
				currentSectionLength = NEW_LINE_SEQUENCE_LENGTH
					+ name.length() + 6;
			}

			// Output next character
			const char_t c = value[i];
			bool encode = false;

			switch (c)
			{
			// special characters
			case ' ':
			case '\t':
			case '\r':
			case '\n':
			case '"':
			case ';':
			case ',':

				encode = true;
				break;

			default:

				encode = (!parserHelpers::isPrint(c) ||
				          !parserHelpers::isAscii(c));

				break;
			}

			if (encode)  // need encoding
			{
				const int h1 = static_cast <unsigned char>(c) / 16;
				const int h2 = static_cast <unsigned char>(c) % 16;

				currentSection += '%';
				currentSection += "0123456789ABCDEF"[h1];
				currentSection += "0123456789ABCDEF"[h2];

				pos += 3;
				currentSectionLength += 3;
			}
			else
			{
				currentSection += value[i];

				++pos;
				++currentSectionLength;
			}
		}

		if (!currentSection.empty())
		{
			sectionText.push_back(currentSection);
			sectionCount++;
		}

		// Output sections
		for (int sectionNumber = 0 ; sectionNumber < sectionCount ; ++sectionNumber)
		{
			os << name;

			if (sectionCount != 1) // no section specifier when only a single one
			{
				os << '*';
				os << sectionNumber;
			}

			os << "*=";

			if (sectionNumber == 0)
			{
				os << m_value.getCharset().getName();
				os << '\'' << /* No language */ '\'';
			}

			os << sectionText[sectionNumber];

			if (sectionNumber + 1 < sectionCount)
			{
				os << ';';
				os << NEW_LINE_SEQUENCE;
				pos = NEW_LINE_SEQUENCE_LENGTH;
			}
		}
	}

	if (newLinePos)
		*newLinePos = pos;
}


const std::vector <ref <const component> > parameter::getChildComponents() const
{
	std::vector <ref <const component> > list;

	list.push_back(ref <const component>::fromPtr(&m_value));

	return list;
}


} // vmime

