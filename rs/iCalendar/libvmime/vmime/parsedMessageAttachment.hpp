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

#ifndef VMIME_PARSEDMESSAGEATTACHMENT_HPP_INCLUDED
#define VMIME_PARSEDMESSAGEATTACHMENT_HPP_INCLUDED


#ifndef VMIME_BUILDING_DOC  // implementation detail


#include "vmime/messageAttachment.hpp"


namespace vmime
{


/** A message attachment that can be generated into a message.
  */
class parsedMessageAttachment : public messageAttachment
{
public:

	parsedMessageAttachment(ref <message> msg);

	const mediaType getType() const;
	const text getDescription() const;
	const word getName() const;

	const ref <const contentHandler> getData() const;

	const encoding getEncoding() const;

	ref <const object> getPart() const;

	ref <const header> getHeader() const;

	ref <message> getMessage() const;

protected:

	void generateIn(ref <bodyPart> parent) const;

private:

	ref <message> m_msg;
	mutable ref <contentHandler> m_data;
};


} // vmime


#endif // !VMIME_BUILDING_DOC


#endif // VMIME_PARSEDMESSAGEATTACHMENT_HPP_INCLUDED

