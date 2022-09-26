#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;

public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) {
        if ( lengthVec->dot(widthVec)!=0 ){
            throw std::runtime_error("error");
        }
        else{
            _lengthVec = lengthVec;
            _widthVec = widthVec;
        }
        /*if ( _lengthVec->a()->x()==_lengthVec->b()->x() && _lengthVec->a()->x()==_widthVec->b()->x() ){ throw std::runtime_error("error"); }
        if ( _lengthVec->a()->y()==_lengthVec->b()->y() && _lengthVec->a()->y()==_widthVec->b()->y() ){ throw std::runtime_error("error"); }*/
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
};