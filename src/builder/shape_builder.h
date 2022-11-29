#pragma once
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include <vector>
#include <stack>

class ShapeBuilder{
private:
    std::stack<CompoundShape*> _compoundshape;
    std::vector<Shape*> _result;
public:
    void buildCircle(const Point *center, const Point *to_radius) {
        TwoDimensionalVector* vec1 = new TwoDimensionalVector (center, to_radius);
        Shape* circle = new Circle (vec1);
        if ( !_compoundshape.empty() ) { _compoundshape.top()->addShape(circle); }
        else { _result.push_back(circle); }
    }

    void buildTriangle(const Point *common_point, const Point *v1_point, const Point *v2_point) {
        TwoDimensionalVector* vec1 = new TwoDimensionalVector (common_point, v1_point);
        TwoDimensionalVector* vec2 = new TwoDimensionalVector (common_point, v2_point);
        Shape* triangle = new Triangle (vec1, vec2);
        if ( !_compoundshape.empty() ) { _compoundshape.top()->addShape(triangle); }
        else { _result.push_back(triangle); }
    }

    void buildRectangle(const Point *common_point, const Point *v1_point, const Point *v2_point) {
        TwoDimensionalVector* vec1 = new TwoDimensionalVector (common_point, v1_point);
        TwoDimensionalVector* vec2 = new TwoDimensionalVector (common_point, v2_point);
        Shape* rectangle = new Rectangle (vec1, vec2);
        if ( !_compoundshape.empty() ) { _compoundshape.top()->addShape(rectangle); }
        else { _result.push_back(rectangle); }
    }

    void buildCompoundShape() {
        CompoundShape* cs1 = new CompoundShape();
        _compoundshape.push(cs1);
    }

    void buildCompoundEnd() {
        CompoundShape* topcs = _compoundshape.top();
        _compoundshape.pop();
        if ( _compoundshape.empty() ) { _result.push_back( topcs ); }
        else { _compoundshape.top()->addShape(topcs); }
    }

    std::vector<Shape*> getResult() { return _result; }
};