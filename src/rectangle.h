#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "point.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"
#include "./iterator/factory/iterator_factory.h"

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

    Iterator *createIterator(IteratorFactory *factory) override { return factory->createIterator(); }

    std::set<const Point*> getPoints() override {
        std::set<const Point*> points;
        std::set<std::string> tmp;
        if ( tmp.find(_lengthVec->a()->info())==tmp.end() ){ tmp.insert(_lengthVec->a()->info()); points.insert(_lengthVec->a()); }
        if ( tmp.find(_lengthVec->b()->info())==tmp.end() ){ tmp.insert(_lengthVec->b()->info()); points.insert(_lengthVec->b()); }
        if ( tmp.find(_widthVec->a()->info())==tmp.end() ){ 
            tmp.insert(_widthVec->a()->info()); points.insert(_widthVec->a());
            const Point tmp = *_lengthVec->a() + *_lengthVec->b() + *_widthVec->a() - *_widthVec->b() - *_widthVec->b();
            points.insert(new Point(tmp.x(), tmp.y()));
        }
        if ( tmp.find(_widthVec->b()->info())==tmp.end() ){ 
            tmp.insert(_widthVec->b()->info()); points.insert(_widthVec->b());
            const Point tmp = *_lengthVec->a() + *_lengthVec->b() + *_widthVec->b() - *_widthVec->a() - *_widthVec->a();
            points.insert(new Point(tmp.x(), tmp.y()));
        }
        return points;
    }

    void accept(ShapeVisitor* visitor) override { visitor->visitRectangle(this); }

    void addShape(Shape *shape) { throw std::runtime_error("error"); }

    void deleteShape(Shape *shape) { throw std::runtime_error("error"); }
};