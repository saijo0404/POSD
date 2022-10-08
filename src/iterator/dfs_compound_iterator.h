#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>

class CompoundShape;

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator
{
private:
    std::list<Shape *> _shapes;
    ForwardIterator _current;
    ForwardIterator _end;
public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        if ( begin!=end ) {
            while (true) {
                _shapes.push_back(*begin);
                Iterator* it = (*begin)->createDFSIterator();
                if ( !it->isDone() ){
                    for ( it->first();!it->isDone();it->next() ){ _shapes.push_back(it->currentItem()); }
                }
                begin++;
                if ( begin==end ) { break; }
            }
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

    bool isDone() const override { return _current==_end;}
};