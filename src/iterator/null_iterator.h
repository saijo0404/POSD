#pragma once

#include "iterator.h"

class NullIterator : public Iterator {
public:
    void first() override { throw "not have the first item"; }

    Shape* currentItem() const override { throw "nothing"; }

    void next() override { throw "can't next item";} 

    bool isDone() const override { return true; }
};