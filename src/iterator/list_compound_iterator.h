#pragma once

#include "./iterator.h"
#include <list>


template <class ForwardIterator>
class ListCompoundIterator : public Iterator {
private:
    std::list<Shape *> _shapes;

public:
    ListCompoundIterator(ForwardIterator begin, ForwardIterator end){
        for (ForwardIterator it = begin; it != end; it++) {
            _shapes.push_back(*it);
        }
    }
    void first() override {}

    Shape *currentItem() const override {
        if (isDone()) { throw "no current item"; }
        return (*_shapes.begin());
    }

    void next() override {
        if (isDone()) { throw "can't next"; }
        _shapes.pop_front();
    }

    bool isDone() const override {
        return _shapes.size() == 0;
    }
};
