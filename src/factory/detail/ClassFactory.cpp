#include "ClassFactory.h"

ClassFactory::~ClassFactory()
{
	for (std::map<std::string, ClassAllocatorBase*>::iterator it = this->registry.begin(); it != this->registry.end(); ++it)
		delete it->second;
}
