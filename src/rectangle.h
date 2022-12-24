#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector _lengthVec;
    TwoDimensionalVector _widthVec;

public:
    Rectangle(TwoDimensionalVector lengthVec, TwoDimensionalVector widthVec) : _lengthVec(lengthVec), _widthVec(widthVec){
        if ( lengthVec.dot(widthVec)!=0 ){ throw "Rectangle error"; }
    }
    ~Rectangle() {}

    double length() const { return _lengthVec.length(); }

    double width() const { return _widthVec.length(); }

    double area() const override { return _lengthVec.length() * _widthVec.length(); }

    double perimeter() const override { return (_lengthVec.length() + _widthVec.length()) * 2; }

    std::string info() const override {
        return "Rectangle (" + _lengthVec.info() + ", " + _widthVec.info() + ")";
    }

    Iterator *createIterator(IteratorFactory *factory) override { return factory->createIterator(); }

    std::set<Point> getPoints() override{
        std::set<Point> points;
        std::set<std::string> tmp;
        if ( tmp.find(_lengthVec.a().info())==tmp.end() ){ tmp.insert(_lengthVec.a().info()); points.insert(_lengthVec.a()); }
        if ( tmp.find(_lengthVec.b().info())==tmp.end() ){ tmp.insert(_lengthVec.b().info()); points.insert(_lengthVec.b()); }
        if ( tmp.find(_widthVec.a().info())==tmp.end() ){ 
            tmp.insert(_widthVec.a().info()); points.insert(_widthVec.a());
            std::map<std::string, double> tmp1;
            tmp1["x"] = _lengthVec.a().x() + _lengthVec.b().x() + _widthVec.a().x() - _widthVec.b().x() - _widthVec.b().x();
            tmp1["y"] = _lengthVec.a().y() + _lengthVec.b().y() + _widthVec.a().y() - _widthVec.b().y() - _widthVec.b().y();
            points.insert(Point(tmp1["x"], tmp1["y"]));
        }
        if ( tmp.find(_widthVec.b().info())==tmp.end() ){ 
            tmp.insert(_widthVec.b().info()); points.insert(_widthVec.b());
            std::map<std::string, double> tmp1;
            tmp1["x"] = _lengthVec.a().x() + _lengthVec.b().x() + _widthVec.b().x() - _widthVec.a().x() - _widthVec.a().x();
            tmp1["y"] = _lengthVec.a().y() + _lengthVec.b().y() + _widthVec.b().y() - _widthVec.a().y() - _widthVec.a().y();
            points.insert(Point(tmp1["x"], tmp1["y"]));
        }
        return points;
    }

    void accept(ShapeVisitor *visitor) override { visitor->visitRectangle(this); }

    void move(double deltaX, double deltaY) override {
        _lengthVec.move(deltaX, deltaY);
        _widthVec.move(deltaX, deltaY);
    }


};