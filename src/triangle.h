#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) {
        double ary[3][2]={0};
        if ( v1->a()->x()==v2->a()->x() && v1->a()->y()==v2->a()->y() ){
            ary[0][0] = v1->a()->x();ary[0][1] = v1->a()->y();
            ary[1][0] = v1->b()->x();ary[1][1] = v1->b()->y();
            ary[2][0] = v2->b()->x();ary[2][1] = v2->b()->y();
        }
        else if ( v1->a()->x()==v2->b()->x() && v1->a()->y()==v2->b()->y() ){
            ary[0][0] = v1->a()->x();ary[0][1] = v1->a()->y();
            ary[1][0] = v1->b()->x();ary[1][1] = v1->b()->y();
            ary[2][0] = v2->a()->x();ary[2][1] = v2->a()->y();
        }
        else if ( v1->b()->x()==v2->a()->x() && v1->b()->y()==v2->a()->y() ){
            ary[0][0] = v1->a()->x();ary[0][1] = v1->a()->y();
            ary[1][0] = v1->b()->x();ary[1][1] = v1->b()->y();
            ary[2][0] = v2->b()->x();ary[2][1] = v2->b()->y();
        }
        else if ( v1->b()->x()==v2->b()->x() && v1->b()->y()==v2->b()->y() ){
            ary[0][0] = v1->a()->x();ary[0][1] = v1->a()->y();
            ary[1][0] = v1->b()->x();ary[1][1] = v1->b()->y();
            ary[2][0] = v2->a()->x();ary[2][1] = v2->a()->y();
        }
        else {
            throw std::runtime_error("error");
        }
        
        if ( ary[0][0]==ary[1][0] && ary[0][0]==ary[2][0] ) { throw std::runtime_error("error"); }
        if ( ary[0][1]==ary[1][1] && ary[0][1]==ary[2][1] ) { throw std::runtime_error("error"); }
        _v1 = v1;
        _v2 = v2;
    }
    ~Triangle() {}

    double area() const override { return _v1->cross(_v2)/2<0?-1*_v1->cross(_v2)/2:_v1->cross(_v2)/2; }

    double perimeter() const override {
        if ( _v1->a()->x()==_v2->a()->x() && _v1->a()->y()==_v2->a()->y() ){ TwoDimensionalVector v3(_v1->b(), _v2->b()); return _v1->length()+_v2->length()+v3.length();}
        else if ( _v1->a()->x()==_v2->b()->x() && _v1->a()->y()==_v2->b()->y() ){TwoDimensionalVector v3(_v1->b(), _v2->a()); return _v1->length()+_v2->length()+v3.length();}
        else if ( _v1->b()->x()==_v2->a()->x() && _v1->b()->y()==_v2->a()->y() ){TwoDimensionalVector v3(_v1->a(), _v2->b()); return _v1->length()+_v2->length()+v3.length();}
        else if ( _v1->b()->x()==_v2->b()->x() && _v1->b()->y()==_v2->b()->y() ){TwoDimensionalVector v3(_v1->a(), _v2->a()); return _v1->length()+_v2->length()+v3.length();} 
        else { return 0; }
    }

    std::string info() const override {
        std::ostringstream ostr;
        ostr << "Triangle (" << _v1->info() << ", " << _v2->info() <<")";
        std::string s = ostr.str();
        return s;
    }
    Iterator* createDFSIterator() override { return new NullIterator(); }

    Iterator* createBFSIterator() override { return new NullIterator(); }
};