#pragma once
#include "./iterator/iterator.h"
class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual ~Shape() {}
    virtual Iterator *createDFSIterator() = 0;
    virtual Iterator *createBFSIterator() = 0;
    virtual void addShape(Shape *shape) { throw std::runtime_error("error"); };
    virtual void deleteShape(Shape *shape) { throw std::runtime_error("error"); };
};
