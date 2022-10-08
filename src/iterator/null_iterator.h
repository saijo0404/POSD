#pragma once

#include "iterator.h"

class NullIterator : public Iterator
{
public:
    void first() override { throw std::string("error");}

    Shape* currentItem() const override { throw std::runtime_error("error"); }

    void next() override { throw std::runtime_error("error"); }

    bool isDone() const override { return true; }
};
