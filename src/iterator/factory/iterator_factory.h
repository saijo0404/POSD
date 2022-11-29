#pragma once

#include "../iterator.h"
#include <list>
#include <string>

class IteratorFactory
{
public:
    virtual Iterator *createIterator() = 0;
    virtual Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) = 0;
    static IteratorFactory* getInstance(std::string name);
protected:
    static void _register(std::string name, IteratorFactory* factory);
};