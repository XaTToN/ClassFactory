/*
* <Class Factory>
* Copyright (C) 2015 Marcel Mueller
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __REGISTRATION_H__
#define __REGISTRATION_H__

#include "ClassFactory.h"

template <class Super, class Sub>
class Registration
{
public:
	Registration(const char* name)
	{
		singleton_default<ClassFactory>::instance()->Register<Super>(name, []() -> Super*
		{
			return new Sub();
		});
	}
};

#endif //__REGISTRATION_H__
