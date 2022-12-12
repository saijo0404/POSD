#pragma once

#include "shape.h"
#include "./iterator/factory/iterator_factory.h"
#include "./iterator/factory/dfs_iterator_factory.h"
#include "./visitor/shape_visitor.h"

#include <list>
#include <set>

class CompoundShape : public Shape{
private:
    std::list<Shape *> _shapes;

public:
    CompoundShape(){}
    CompoundShape(Shape **shapes, int size) : _shapes(shapes, shapes + size) {}
    CompoundShape(std::list<Shape*> shapes) {
        for (std::list<Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); it++) { _shapes.push_back(*it); }
    }
    ~CompoundShape() {
        for (std::list<Shape *>::iterator it = _shapes.begin(); it != _shapes.end(); ++it) {
            delete (*it);
        }
        _shapes.clear();
    }

    double area() const override {
        double result = 0;
        for ( std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++ ){
            result = result + (*it)->area();
        }
        return result;
    }

    double perimeter() const override {
        double result = 0;
        for ( std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++ ){
            result = result + (*it)->perimeter();
        }
        return result;
    }

    std::string info() const override {
        /*std::ostringstream ostr;
        ostr << "CompoundShape ("; 
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) {
            ostr << (*it)->info();
            if ( std::next(it,1)!=_shapes.end() ){ ostr << ", "; }
        }
        ostr <<")";
        std::string s = ostr.str();
        return s;*/
        std::string result = "CompoundShape (";
        for (std::list<Shape *>::const_iterator it = _shapes.begin(); it != _shapes.end(); ++it)
        {
            result += (*it)->info();
            if (std::next(it) != _shapes.end())
            {
                result += ", ";
            }
        }
        result += ")";
        return result;
    }

    Iterator *createIterator(IteratorFactory *factory) override { return factory->createIterator(_shapes.begin(), _shapes.end()); }

    void addShape(Shape *shape) override { _shapes.push_back(shape); }

    void deleteShape(Shape *shape) override {
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) {
            if ( shape==(*it) ){ 
                delete *it;
                _shapes.erase(it);
                break; 
            }
            else {
                Iterator *shapeIt = (*it)->createIterator(IteratorFactory::getInstance("DFS"));
                if (!shapeIt->isDone()){(*it)->deleteShape(shape);}
                delete shapeIt;
            }
        }
    }

    std::set<Point> getPoints() override {
        std::set<Point> points;
        std::set<std::string> tmp;
        for ( std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++ ) {
            std::set<Point> tpoints = (*it)->getPoints();
            for ( std::set<Point>::const_iterator i = tpoints.begin(); i!=tpoints.end();i++ ) {
                if ( tmp.find((*i).info())==tmp.end() ){ tmp.insert((*i).info()); points.insert(*i);}
            }
        }
        return points;
    }

    void accept(ShapeVisitor *visitor) override { visitor->visitCompoundShape(this); }
};