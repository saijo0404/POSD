#pragma once

#include "point.h"

class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b) {
        _a = a;
        _b = b;
    }
    ~TwoDimensionalVector() {}

    const Point *a() const { return _a; }

    const Point *b() const { return _b; }

    double length() const { 
        const Point tmp = (*_a)-(*_b);
        return sqrt(tmp.x()*tmp.x()+tmp.y()*tmp.y());
    }

    double dot(const TwoDimensionalVector *vec) const {
        const Point tmp = (*_b)-(*_a);
        const Point tmp1 = (*vec->_b)-(*vec->_a);
        return (tmp.x()*tmp1.x()+tmp.y()*tmp1.y());
    }

    double cross(const TwoDimensionalVector *vec) const { 
        const Point tmp = (*_b)-(*_a);
        const Point tmp1 = (*vec->_b)-(*vec->_a);
        return (tmp.x()*tmp1.y()-tmp1.x()*tmp.y());
    }

    std::string info() const {
        std::ostringstream ostr;
        ostr << "Vector (" << _a->info() << ", " << _b->info() <<")";
        std::string s = ostr.str();
        return s;
    }
};