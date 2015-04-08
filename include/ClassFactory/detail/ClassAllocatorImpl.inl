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

#include <exception>

template<class T> const std::function<T*(void)>& ClassAllocatorBase::get() const
{
	auto dptr = dynamic_cast<const ClassAllocator<T>*>(this);
	if (!dptr)
	{
		throw std::bad_cast();
	}

	return dynamic_cast<const ClassAllocator<T>&>(*this).get();
}

template<class T, class U> void ClassAllocatorBase::setValue(const std::function<U*(void)>& rhs)
{
	return dynamic_cast<ClassAllocator<T>&>(*this).setValue(rhs);
}