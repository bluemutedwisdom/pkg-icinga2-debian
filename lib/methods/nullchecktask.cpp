/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2017 Icinga Development Team (https://www.icinga.com/)  *
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

#ifndef _WIN32
#	include <stdlib.h>
#endif /* _WIN32 */
#include "methods/nullchecktask.hpp"
#include "icinga/perfdatavalue.hpp"
#include "icinga/icingaapplication.hpp"
#include "base/utility.hpp"
#include "base/convert.hpp"
#include "base/function.hpp"
#include "base/logger.hpp"

using namespace icinga;

REGISTER_SCRIPTFUNCTION_NS(Internal, NullCheck, &NullCheckTask::ScriptFunc);

void NullCheckTask::ScriptFunc(const Checkable::Ptr& service, const CheckResult::Ptr& cr,
    const Dictionary::Ptr& resolvedMacros, bool useResolvedMacros)
{
	if (resolvedMacros && !useResolvedMacros)
		return;

	String output = "Hello from ";
	output += IcingaApplication::GetInstance()->GetNodeName();

	Array::Ptr perfdata = new Array();
	perfdata->Add(new PerfdataValue("time", Convert::ToDouble(Utility::GetTime())));

	cr->SetOutput(output);
	cr->SetPerformanceData(perfdata);
	cr->SetState(ServiceOK);

	service->ProcessCheckResult(cr);
}
