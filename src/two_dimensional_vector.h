#pragma once

#include <cmath>
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

    double length() const { return sqrt((_a->x()-_b->x())*(_a->x()-_b->x())+(_a->y()-_b->y())*(_a->y()-_b->y())); }

    double dot(const TwoDimensionalVector *vec) const { return (_b->x()-_a->x())*(vec->_b->x()-vec->_a->x())+(_b->y()-_a->y())*(vec->_b->y()-vec->_a->y()); }

    double cross(const TwoDimensionalVector *vec) const { 
        return (_b->x()-_a->x())*(vec->_b->y()-vec->_a->y())-(vec->_b->x()-vec->_a->x())*(_b->y()-_a->y()); }

    std::string info() const {
        std::ostringstream ostr;
        ostr << "Vector (" << _a->info() << ", " << _b->info() <<")";
        std::string s = ostr.str();
        return s;
    }
};