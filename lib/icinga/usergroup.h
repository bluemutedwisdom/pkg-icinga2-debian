/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2013 Icinga Development Team (http://www.icinga.org/)   *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef USERGROUP_H
#define USERGROUP_H

#include "icinga/i2-icinga.h"
#include "icinga/usergroup.th"
#include "icinga/user.h"

namespace icinga
{

/**
 * An Icinga user group.
 *
 * @ingroup icinga
 */
class I2_ICINGA_API UserGroup : public ObjectImpl<UserGroup>
{
public:
	DECLARE_PTR_TYPEDEFS(UserGroup);
	DECLARE_TYPENAME(UserGroup);

	std::set<User::Ptr> GetMembers(void) const;
	void AddMember(const User::Ptr& user);
	void RemoveMember(const User::Ptr& user);

private:
	std::set<User::Ptr> m_Members;
};

}

#endif /* USERGROUP_H */
