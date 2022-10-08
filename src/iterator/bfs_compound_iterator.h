#pragma once

#include "iterator.h"
#include "../shape.h"

#include <list>
#include <queue>

class CompoundShape;

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator
{
private:
    std::list<Shape *> _shapes;
    std::list<Shape *> _tmp;
    ForwardIterator _current;
    ForwardIterator _end;
public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        _current = begin;
        _end = end;
        if ( begin!=end ) { 
            while (true) {
                _shapes.push_back(*begin);
                begin++;
                if ( begin==end ) { break; }
            }
            for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) {
                Iterator* i = (*it)->createBFSIterator();
                if ( !i->isDone() ){
                    for ( i->first();!i->isDone();i->next() ){
                        _tmp.push_back(i->currentItem());
                    }
                }
            }
            for (std::list<Shape*>::const_iterator it = _tmp.begin(); it != _tmp.end(); it++ ){ _shapes.push_back(*it); }
        }
        _current = _shapes.begin();
        _end = _shapes.end();
    }

    void first() override { _current = _shapes.begin(); }

    Shape* currentItem() const override { 
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) { 
            if ( _current==it ) { return *_current; } 
        }
        throw std::runtime_error("error");
     }

    void next() override { 
        if ( _current==_end ){ throw std::runtime_error("error"); }
        else { _current++; }
    }

    bool isDone() const override { return _current == _end; }
};
