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
// You should have received a copy of the GNU General Public License along along
// with this program; if not, write to the Free Software Foundation, Inc., Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA..
//

#include "vmime/net/pop3/POP3Utils.hpp"

#include <sstream>


namespace vmime {
namespace net {
namespace pop3 {


// static
void POP3Utils::parseMultiListOrUidlResponse(const string& response, std::map <int, string>& result)
{
	std::istringstream iss(response);
	std::map <int, string> ids;

	string line;

	while (std::getline(iss, line))
	{
		string::iterator it = line.begin();

		while (it != line.end() && (*it == ' ' || *it == '\t'))
			++it;

		if (it != line.end())
		{
			int number = 0;

			while (it != line.end() && (*it >= '0' && *it <= '9'))
			{
				number = (number * 10) + (*it - '0');
				++it;
			}

			while (it != line.end() && !(*it == ' ' || *it == '\t')) ++it;
			while (it != line.end() && (*it == ' ' || *it == '\t')) ++it;

			if (it != line.end())
			{
				result.insert(std::map <int, string>::value_type(number, string(it, line.end())));
			}
		}
	}
}


} // pop3
} // net
} // vmime

