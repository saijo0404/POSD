#pragma once

#include "./iterator_factory.h"

class DFSIteratorFactory : public IteratorFactory {
private:
    static DFSIteratorFactory _instance;
public:
    DFSIteratorFactory();
    Iterator *createIterator();
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end);
};