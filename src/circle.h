#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;

public:
    Circle(TwoDimensionalVector *radiusVec) { _radiusVec = radiusVec; }
    ~Circle() {}

    double radius() const { return _radiusVec->length(); }

    double area() const override { return M_PI * radius() *radius(); }

    double perimeter() const override { return 2 * M_PI * radius(); }

    std::string info() const override {
        std::ostringstream ostr;
        ostr << "Circle (" << _radiusVec->info() <<")";
        std::string s = ostr.str();
        return s;
    }
};