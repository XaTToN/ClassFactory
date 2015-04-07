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

#include "libClassFactory.h"

class Super
{
	FACTORY_REGISTER_SUPER_CLASS(Super)
public:
	virtual ~Super() {}
	virtual void print() { std::cout << "I am the super class" << std::endl; }
};
FACTORY_FINISH_SUPER_REGISTRATION(Super, "Super")

class DOne : public Super
{
	FACTORY_REGISTER_DERIVATED_CLASS(Super, DOne)
public:
	virtual ~DOne() {}
	virtual void print() { std::cout << "I am class DOne" << std::endl; }
};
FACTORY_FINISH_DERIVATED_REGISTRATION(Super, DOne, "DOne")

class DTwo : public Super
{
	FACTORY_REGISTER_DERIVATED_CLASS(Super, DTwo)
public:
	virtual ~DTwo() {}
	virtual void print() { std::cout << "I am class DTwo" << std::endl; }
};
FACTORY_FINISH_DERIVATED_REGISTRATION(Super, DTwo, "DTwo")

class DBad : public Super
{
	FACTORY_REGISTER_DERIVATED_CLASS(DBad, DBad)
public:
	virtual ~DBad() {}
	virtual void print() { std::cout << "I am class DBad" << std::endl; }
};
FACTORY_FINISH_DERIVATED_REGISTRATION(DBad, DBad, "DBad")
 
int main()
{
	char c = 'n';
	std::string name = "";

	do
	{
		std::cout << "Name of class to create: ";
		std::cin >> name;

		try
		{
			auto ptr = sClassFactory->Alloc<Super>(name);
			ptr->print();
		}
		catch (...)
		{
			std::cout << "An error occurred!" << std::endl;
		}

		std::cout << "Create another class? (y/n): ";
		std::cin >> c;
	} while (c == 'y');
}
