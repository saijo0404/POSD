#pragma once

#include "iterator.h"
#include "../shape.h"
#include "./factory/bfs_iterator_factory.h"
#include <queue>
#include <list>

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator {
private:
    std::list<Shape *> _shapes; 
public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        std::list<Shape*> buffer;
        for(ForwardIterator it=begin; it!=end; it++) {
            _shapes.push_back(*it);
        }
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) {
            Iterator* i = (*it)->createIterator(IteratorFactory::getInstance("BFS"));
            if ( !i->isDone() ){
                for ( i->first();!i->isDone();i->next() ){
                    buffer.push_back(i->currentItem());
                }
            }
            delete i;
        }
        for (std::list<Shape*>::const_iterator it = buffer.begin(); it != buffer.end(); it++ ){ _shapes.push_back(*it); }
    }

    void first() override {}

    Shape* currentItem() const override {
        if(isDone()) { throw "no current item"; }
        return (*_shapes.begin());
    }

    void next() override {
        if (isDone()) { throw "can't next"; }
        _shapes.pop_front();
    }

    bool isDone() const override { return _shapes.size() == 0; }
};