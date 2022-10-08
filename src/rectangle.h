#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;
public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) {
        if ( lengthVec->dot(widthVec)!=0 ){ throw std::runtime_error("error"); }
        else{
            _lengthVec = lengthVec;
            _widthVec = widthVec;
        }
    }
    ~Rectangle() {}

    double length() const { return _lengthVec->length(); }

    double width() const { return _widthVec->length(); }

    double area() const override { return length()*width(); }

    double perimeter() const override { return (length()+width())*2; }

    std::string info() const override {
        std::ostringstream ostr;
        ostr << "Rectangle (" << _lengthVec->info() << ", " << _widthVec->info() <<")";
        std::string s = ostr.str();
        return s;
    }
    Iterator* createDFSIterator() override { return new NullIterator(); }

    Iterator* createBFSIterator() override { return new NullIterator(); }
};