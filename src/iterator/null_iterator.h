#pragma once

#include "iterator.h"

class NullIterator : public Iterator
{
public:
    void first() override { throw std::string("error");}

    Shape* currentItem() const override { throw std::string("error"); }

    void next() override { throw std::string("error"); }

    bool isDone() const override { return true; }
};
