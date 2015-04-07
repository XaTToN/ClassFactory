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

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <typename T>
class singleton_default
{
private:
	struct object_creator
	{
		object_creator() { singleton_default<T>::instance(); }
		inline void do_nothing() const { }
	};
	static object_creator create_object;

	singleton_default();

public:
	typedef T object_type;

	static object_type * instance()
	{
		static object_type obj;

		create_object.do_nothing();

		return &obj;
	}
};
template <typename T>
typename singleton_default<T>::object_creator
singleton_default<T>::create_object;

#endif //__SINGLETON_H__
