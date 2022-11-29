#pragma once

#include "iterator_factory.h"
#include "../null_iterator.h"
#include "../list_compound_iterator.h"

class ListIteratorFactory : public IteratorFactory {
private:
    static ListIteratorFactory _instance;
public:
    ListIteratorFactory();
    Iterator *createIterator();
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end);
};