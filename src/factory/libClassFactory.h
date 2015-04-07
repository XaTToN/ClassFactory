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

#ifndef __LIB_CLASS_FACTORY_H__
#define __LIB_CLASS_FACTORY_H__

#include "ClassAllocator.h"
#include "Registration.h"
#include "ClassFactory.h"

#define sClassFactory singleton_default<ClassFactory>::instance()

#define FACTORY_REGISTER_SUPER_CLASS(SUPER) \
	static Registration<SUPER, SUPER> reg;

#define FACTORY_FINISH_SUPER_REGISTRATION(SUPER, NAME) \
	Registration<SUPER, SUPER> SUPER::reg(NAME);

#define FACTORY_REGISTER_DERIVATED_CLASS(SUPER, SUB) \
	static Registration<SUPER, SUB> reg;

#define FACTORY_FINISH_DERIVATED_REGISTRATION(SUPER, SUB, NAME) \
	Registration<SUPER, SUB> SUB::reg(NAME);

#endif //_LIB_CLASS_FACTORY_H__