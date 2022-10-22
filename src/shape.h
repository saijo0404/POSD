#pragma once

#include <string>
#include <set>

class Point;
class Iterator;
class ShapeVisitor;
class IteratorFactory;

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual Iterator *createDFSIterator() = 0;
    virtual Iterator *createBFSIterator() = 0;
    virtual Iterator* createIterator(IteratorFactory * factory) = 0;
    virtual std::set<const Point*> getPoints() = 0;
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual void addShape(Shape *shape) = 0;
    virtual void deleteShape(Shape *shape) = 0;
    virtual ~Shape() {}
};
