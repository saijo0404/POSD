#pragma once

#include <string>
#include <cmath>
#include <set>
#include "shape.h"
#include "point.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"
#include "./iterator/factory/iterator_factory.h"

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
    Iterator* createDFSIterator() override { return new NullIterator(); }

    Iterator* createBFSIterator() override { return new NullIterator(); }

    Iterator *createIterator(IteratorFactory *factory) override { return factory->createIterator(); }

    std::set<const Point*> getPoints() {
        std::set<const Point*> points;
        points.insert(new Point(_radiusVec->a()->x()+_radiusVec->length(),_radiusVec->a()->y()+_radiusVec->length()));
        points.insert(new Point(_radiusVec->a()->x()-_radiusVec->length(),_radiusVec->a()->y()-_radiusVec->length()));
        return points;
    }

    void accept(ShapeVisitor* visitor) { visitor->visitCircle(this); }

    void addShape(Shape *shape) { throw std::runtime_error("error"); }

    void deleteShape(Shape *shape) { throw std::runtime_error("error"); }
};