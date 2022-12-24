#pragma once

#include <string>
#include <vector>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape{
private:
    TwoDimensionalVector _v1;
    TwoDimensionalVector _v2;

public:
    Triangle(TwoDimensionalVector v1, TwoDimensionalVector v2) : _v1(v1), _v2(v2){
        std::vector<Point> points;
        std::set<std::string> tmp;
        if ( tmp.find(v1.a().info())==tmp.end() ) { tmp.insert(v1.a().info()); points.push_back(v1.a());}
        if ( tmp.find(v1.b().info())==tmp.end() ) { tmp.insert(v1.b().info()); points.push_back(v1.b());}
        if ( tmp.find(v2.a().info())==tmp.end() ) { tmp.insert(v2.a().info()); points.push_back(v2.a());}
        if ( tmp.find(v2.b().info())==tmp.end() ) { tmp.insert(v2.b().info()); points.push_back(v2.b());}
        if ( tmp.size()!=3 ) { throw "Triangle error"; }
        if ( points[0].x()==points[1].x() && points[0].x()==points[2].x() ) { throw "Triangle error"; }
        if ( points[0].y()==points[1].y() && points[0].y()==points[2].y() ) { throw "Triangle error"; }
    }
    ~Triangle() {}

    double area() const override { return _v1.cross(_v2)/2<0?-1*_v1.cross(_v2)/2:_v1.cross(_v2)/2; }

    double perimeter() const override {
        if ( _v1.a().info()==_v2.a().info() ){ TwoDimensionalVector v3(_v1.b(), _v2.b()); return _v1.length()+_v2.length()+v3.length();}
        if ( _v1.a().info()==_v2.b().info() ){ TwoDimensionalVector v3(_v1.b(), _v2.a()); return _v1.length()+_v2.length()+v3.length();}
        if ( _v1.b().info()==_v2.a().info() ){ TwoDimensionalVector v3(_v1.a(), _v2.b()); return _v1.length()+_v2.length()+v3.length();}
        if ( _v1.b().info()==_v2.b().info() ){ TwoDimensionalVector v3(_v1.a(), _v2.a()); return _v1.length()+_v2.length()+v3.length();} 
        return 0;
    }

    std::string info() const override{
        return "Triangle (" + _v1.info() + ", " + _v2.info() + ")";
    }

    Iterator *createIterator(IteratorFactory *factory) override{ return factory->createIterator(); }

    std::set<Point> getPoints() override {
        std::set<Point> points;
        std::set<std::string> info;
        if ( info.find(_v1.a().info())==info.end() ){ info.insert(_v1.a().info()); points.insert(_v1.a()); }
        if ( info.find(_v1.b().info())==info.end() ){ info.insert(_v1.b().info()); points.insert(_v1.b()); }
        if ( info.find(_v2.a().info())==info.end() ){ info.insert(_v2.a().info()); points.insert(_v2.a()); }
        if ( info.find(_v2.b().info())==info.end() ){ info.insert(_v2.b().info()); points.insert(_v2.b()); }
        return points;
    }

    void accept(ShapeVisitor *visitor) override{ visitor->visitTriangle(this); }

    void move(double deltaX, double deltaY) override {
        _v1.move(deltaX, deltaY);
        _v2.move(deltaX, deltaY);
    }

};