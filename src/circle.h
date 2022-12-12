#pragma once

#include <string>
#include <cmath>
#include <set>
#include "two_dimensional_vector.h"
#include "shape.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Circle : public Shape{
private:
    TwoDimensionalVector _radiusVec;

public:
    Circle(TwoDimensionalVector radiusVec) : _radiusVec(radiusVec) {}
    ~Circle() {}

    double radius() const { return _radiusVec.length(); }

    double area() const override { return M_PI * radius() *radius(); }

    double perimeter() const override { return 2 * M_PI * radius(); }

    std::string info() const override {
        /*std::ostringstream ostr;
        ostr << "Circle (" << _radiusVec.info() <<")";
        std::string s = ostr.str();
        return s;*/
        return "Circle (" + _radiusVec.info() + ")";
    }

    Iterator *createIterator(IteratorFactory *factory) override { return factory->createIterator(); }

    std::set<Point> getPoints() override {
        std::set<Point> points;
        points.insert(Point(_radiusVec.a()->x()+_radiusVec.length(),_radiusVec.a()->y()+_radiusVec.length()));
        points.insert(Point(_radiusVec.a()->x()-_radiusVec.length(),_radiusVec.a()->y()-_radiusVec.length()));
        return points;
    }

    void accept(ShapeVisitor *visitor) override { visitor->visitCircle(this); }
};