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

#ifndef __CLASS_FACTORY_H__
#define __CLASS_FACTORY_H__

#include "Singleton.h"
#include "ClassAllocator.h"

#include <memory>
#include <string>
#include <map>
#include <exception>

/*! Interface for the factory wrapped as a singleton*/
class ClassFactory
{
friend class singleton_default<ClassFactory>;
private:
	ClassFactory() {}
	~ClassFactory();
public:
	template <class T> void Register(const std::string& class_name, const std::function<T*(void)>& proc);
	template <class T> std::unique_ptr<T> Alloc(const std::string& class_name);

private:
	std::map<std::string, ClassAllocatorBase*> registry;
};

#include "ClassFactoryImpl.inl"

#endif //__CLASS_FACTORY_H__