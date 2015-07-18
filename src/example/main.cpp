/*
* <Example Project for Class Factory>
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

#include <iostream>
#include <string>

#include <ClassFactory/LCF.h>

class SuperClass
{
FACTORY_REGISTER_SUPER_CLASS(SuperClass)
protected:
	typedef SuperClass Super;
public:
	virtual ~SuperClass() {}
	virtual void print() { std::cout << "I am the SuperClass class" << std::endl; }
};
FACTORY_FINISH_SUPER_REGISTRATION(SuperClass, "SuperClass")

class DOne : public SuperClass
{
	FACTORY_REGISTER_DERIVATED_CLASS(DOne)
public:
	virtual ~DOne() {}
	virtual void print() { std::cout << "I am class DOne" << std::endl; }
};
FACTORY_FINISH_DERIVATED_REGISTRATION(DOne, "DOne")

class DTwo : public SuperClass
{
	FACTORY_REGISTER_DERIVATED_CLASS(DTwo)
public:
	virtual ~DTwo() {}
	virtual void print() { std::cout << "I am class DTwo" << std::endl; }
};
FACTORY_FINISH_DERIVATED_REGISTRATION(DTwo, "DTwo")

int main()
{
	char c = 'n';
	std::string name = "";

	do
	{
		std::cout << "Name of class to create: ";
		std::cin >> name;

		auto ptr = sClassFactory->Alloc<SuperClass>(name);

		if (ptr)
			ptr->print();
		else
			std::cout << "An error occurred!" << std::endl;

		std::cout << "Create another class? (y/n): ";
		std::cin >> c;
	} while (c == 'y');
}
