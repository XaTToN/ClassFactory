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

template <class T> void ClassFactory::Register(const std::string& class_name, const std::function<T*(void)>& proc)
{
	int oldsize = this->registry.size();
	ClassAllocator<T>* alloc = new ClassAllocator<T>(proc);
	this->registry.insert(std::pair<std::string, ClassAllocatorBase*>(class_name, alloc));

	if (oldsize == registry.size())
		delete alloc;
}

template <class T> std::unique_ptr<T> ClassFactory::Alloc(const std::string& class_name)
{
	std::map<std::string, ClassAllocatorBase*>::iterator it = this->registry.find(class_name);

	if (it == this->registry.end())
	{
		return nullptr;
	}

	try
	{
		it->second->get<T>();
	}
	catch (...)
	{
		return nullptr;
	}

	return std::unique_ptr<T>(it->second->get<T>()());
}