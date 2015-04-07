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

#ifndef __CLASS_ALLOCATOR_H__
#define __CLASS_ALLOCATOR_H__

#include <functional>

class ClassAllocatorBase
{
public:
	virtual ~ClassAllocatorBase() {}
	template <class T> const std::function<T*(void)>& get() const;
	template <class T, class U> void setValue(const std::function<U*(void)>& rhs);
};

template <typename T>
class ClassAllocator : public ClassAllocatorBase
{
public:
	ClassAllocator(const std::function<T*(void)>& rhs) : value(rhs) {}
	const std::function<T*(void)>& get() const { return value; }
	void setValue(const std::function<T*(void)>& rhs) { value = rhs; }
private:
	std::function<T*(void)> value;
};

#include "ClassAllocatorImpl.inl"

#endif //__CLASS_ALLOCATOR_H__