#pragma once

#include <list>
#include <set>
#include "shape.h"
#include "point.h"
#include "two_dimensional_vector.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"
#include "./visitor/shape_visitor.h"
#include "./iterator/factory/iterator_factory.h"

class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;
public:
    CompoundShape(Shape **shapes, int size)
        :_shapes(shapes, shapes + size) {}
    CompoundShape(std::list<Shape*> shapes) {
        for (std::list<Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); it++) {
            _shapes.push_back(*it);
        }
    }
    CompoundShape() {}
    ~CompoundShape() {}

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
        std::ostringstream ostr;
        ostr << "CompoundShape ("; 
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) {
            ostr << (*it)->info();
            if ( std::next(it,1)!=_shapes.end() ){ ostr << ", "; }
        }
        ostr <<")";
        std::string s = ostr.str();
        return s;
    }
    void addShape(Shape* shape) override { _shapes.push_back(shape); }

    void deleteShape(Shape* shape) override {
        for (std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++) {
            if ( shape->info()==(*it)->info() ){ _shapes.erase(it++); it--;}
        }
    }
    Iterator *createDFSIterator() override { return new DFSCompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(),_shapes.end()); }
    Iterator *createBFSIterator() override { return new BFSCompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(),_shapes.end()); }
    Iterator *createIterator(IteratorFactory *factory) override { return factory->createIterator(_shapes.begin(),_shapes.end()); }

    std::set<const Point*> getPoints() {
        std::set<const Point*> points;
        std::set<std::string> tmp;
        for ( std::list<Shape*>::const_iterator it = _shapes.begin(); it != _shapes.end(); it++ ) {
            std::set<const Point*> tpoints = (*it)->getPoints();
            for ( std::set<const Point*>::const_iterator i = tpoints.begin(); i!=tpoints.end();i++ ) {
                if ( tmp.find((*i)->info())==tmp.end() ){ tmp.insert((*i)->info()); points.insert(*i);}
            }
        }
        return points;
    }

    void accept(ShapeVisitor* visitor) {
        visitor->visitCompoundShape(this);
    };
};
