#pragma once

#include "iterator.h"
#include "../shape.h"
#include "./factory/dfs_iterator_factory.h"
#include <list>


template<class ForwardIterator>
class DFSCompoundIterator : public Iterator {
private:
    std::list<Shape *> _shapes;
public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        for(ForwardIterator it=begin; it!=end; it++){
            Iterator *itt = (*it)->createIterator(IteratorFactory::getInstance("DFS"));
            if( !itt->isDone() ) {
                _shapes.push_back(*it);
                for (;!itt->isDone();itt->next() ){ _shapes.push_back(itt->currentItem()); }
            }
            else { _shapes.push_back(*it); }
            delete itt;
        }
    }

    void first() override {}

    Shape* currentItem() const override {
        if(isDone()) { throw "no current item"; }
        return *_shapes.begin();
    }

    void next() override {
        if (isDone()) { throw "can't next"; }
        _shapes.pop_front();
    }

    bool isDone() const override { return _shapes.size() == 0; }
};