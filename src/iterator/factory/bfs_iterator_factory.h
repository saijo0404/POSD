#pragma once

#include "./iterator_factory.h"

class BFSIteratorFactory : public IteratorFactory {
private:
    static BFSIteratorFactory _instance;
public:
    BFSIteratorFactory();
    Iterator *createIterator();
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end);
};